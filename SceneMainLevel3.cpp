#include "DxLib.h"

#include "SceneMainLevel3.h"
#include "SceneTitle.h"
#include "SceneClear3.h"
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

	m_countTimer = 0;
	m_EcountTimer = 0;
}

SceneBase* SceneMainLevel3::update()
{

	true;

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
		return (new SceneClear3);
	}

	void enemy();
	{
		m_EcountTimer++;
		if (m_EcountTimer >= 150)
		{
			m_ePos.x += 0.8;

			if (m_ePos.x >= GoalLineX)
			{
				return(new SceneFail);
			}
		}
		
	}

	return this;
}

void SceneMainLevel3::draw()
{
	if (true)
	{
		SetFontSize(64);

		DrawString(240, 200, "3", GetColor(0, 255, 0));
		m_countTimer++;

		if (m_countTimer > 50)
		{
			DrawString(280, 200, "2", GetColor(0, 255, 0));
			
			if (m_countTimer > 100)
			{
				DrawString(320, 200, "1...", GetColor(0, 255, 0));
				
				if (m_countTimer > 150)
				{
					DrawGraph(0, 0, m_handle, TRUE);

					SetFontSize(32);
					DrawString(0, 0, "ƒŒƒxƒ‹3", GetColor(0, 255, 255));
					DrawLine(GoalLineX, GoalLineY, GoalLineX, 480, GetColor(255, 0, 255), 20);
					DrawGraph(m_pos.x, m_pos.y, m_Phandle, TRUE);
					DrawTurnGraph(m_ePos.x, m_ePos.y, m_Ehandle, TRUE);
				}
			}
		}
	}
}