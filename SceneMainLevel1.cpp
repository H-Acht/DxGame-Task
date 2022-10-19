#include "DxLib.h"

#include "SceneMainLevel1.h"
#include "SceneTitle.h"
#include "SceneClear1.h"
#include "SceneFail.h"

#include "game.h"


void SceneMainLevel1::init()
{
	m_pos.x = 100.0f;
	m_pos.y = 120.0f;

	m_ePos.x = 100.0f;
	m_ePos.y = 300.0f;

	GoalLineX = 600;
	GoalLineY = 0;

	m_handle = LoadGraph("BG/background_A.jpg");
	m_Phandle = LoadGraph("CC/Snails_PP.png");
	m_Ehandle = LoadGraph("CC/Snails_AA.png");

	m_countTimer = 0;
	m_EcountTimer = 0;
}

SceneBase* SceneMainLevel1::update()
{	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	static int push = 0;

	if (padState & PAD_INPUT_1) 
	{
		if (push == 0) 
		{
			m_pos.x += 5.0f;
			PlaySoundFile("SE/PushSound1.mp3", DX_PLAYTYPE_BACK);
		}
		push = 1;
	}
	else if(padState & PAD_INPUT_2)
	{
		if (push == 0)
		{
			m_pos.x += 5.0f;
			PlaySoundFile("SE/PushSound1.mp3", DX_PLAYTYPE_BACK) ;
		}
		push = 1;
	}
	else
	{
		push = 0;
	}

	if (padState & PAD_INPUT_4)
	{
		DeleteGraph(m_handle);
		DeleteGraph(m_Phandle);
		DeleteGraph(m_Ehandle);
		return (new SceneTitle);
	}

	if (m_pos.x >= GoalLineX)
	{
		DeleteGraph(m_handle);
		DeleteGraph(m_Phandle);
		DeleteGraph(m_Ehandle);
		return (new SceneClear1);
	}

	void enemy();
	{
		m_EcountTimer++;
		if (m_EcountTimer >= 150)
		{
			m_ePos.x += 0.3f;

			if (m_ePos.x >= GoalLineX)
			{
				DeleteGraph(m_handle);
				DeleteGraph(m_Phandle);
				DeleteGraph(m_Ehandle);
				return(new SceneFail);
			}
		}
	}
	return this;
}

void SceneMainLevel1::draw()
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
					DrawGraph(0, 0, static_cast<int> (m_handle), TRUE);

					SetFontSize(32);
					DrawString(0, 0, "ƒŒƒxƒ‹1", GetColor(0, 255, 255));
					DrawLine(GoalLineX, GoalLineY, GoalLineX, 480, GetColor(255, 0, 255), 20);
					DrawGraph(static_cast<int> (m_pos.x), static_cast<int> (m_pos.y), m_Phandle, TRUE);
					DrawTurnGraph(static_cast<int> (m_ePos.x), static_cast<int> (m_ePos.y), m_Ehandle, TRUE);
				}
			}
		}
	}
}