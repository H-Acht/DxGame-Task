#include "DxLib.h"

#include "SceneMainLevel3.h"
#include "SceneTitle.h"
#include "SceneClear.h"
#include "SceneFail.h"

#include "game.h"


void SceneMainLevel3::init()
{
	m_pos.x = 100.0f;
	m_pos.y = 120.0f;

	m_ePos.x = 100.0f;
	m_ePos.y = 300.0f;

	GoalLineX = 600;
	GoalLineY = 0;

	m_handle = LoadGraph("BG/background_C.jpg");
	m_Phandle = LoadGraph("CC/Snails_PP.png");
	m_Ehandle = LoadGraph("CC/Snails_CC.png");
}

SceneBase* SceneMainLevel3::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	static int push = 0;

	if (padState & PAD_INPUT_1)
	{
		if (push == 0)
		{
			m_pos.x += 5.0f;
		}
		push = 1;
	}
	else if (padState & PAD_INPUT_2)
	{
		if (push == 0)
		{
			m_pos.x += 5.0f;
		}
		push = 1;
	}
	else
	{
		push = 0;
	}

	if (padState & PAD_INPUT_3)
	{
		return (new SceneTitle);
	}

	if (m_pos.x >= GoalLineX)
	{
		return (new SceneClear);
	}

	void enemy();
	{
		m_ePos.x += 0.8;

		if (m_ePos.x >= GoalLineX)
		{
			return(new SceneFail);
		}
	}

	return this;
}

void SceneMainLevel3::draw()
{
	DrawGraph(0, 0, m_handle, TRUE);

	DrawString(0, 0, "ƒŒƒxƒ‹3", GetColor(0, 255, 255));
	DrawLine(GoalLineX, GoalLineY, GoalLineX, 480, GetColor(255, 0, 255), 20);
	DrawGraph(m_pos.x,m_pos.y, m_Phandle, TRUE);
	DrawTurnGraph(m_ePos.x, m_ePos.y, m_Ehandle, TRUE);

}