#include "DxLib.h"
#include "game.h"
#include "SceneErrorMain.h"
#include "SceneErrorTitle.h"
#include "SceneTitle.h"

void SceneErrorMain::init()
{
	m_pos.x = 100.0f;
	m_pos.y = 120.0f;

	m_ePos.x = 0.0f;
	m_ePos.y = 100.0f;

	GoalLineX = 600;
	GoalLineY = 0;

	m_handle = LoadGraph("BG/te.jpg");
	m_Phandle = LoadGraph("CC/Snails_PP.png");
	m_Ehandle = LoadGraph("CC/Snails_AA.png");

	m_countTimer = 0;
	m_EcountTimer = 0;

}

SceneBase* SceneErrorMain::update()
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
		return (new SceneErrorTitle);
	}

	if (m_pos.x >= GoalLineX)
	{
		DeleteGraph(m_handle);
		DeleteGraph(m_Phandle);
		DeleteGraph(m_Ehandle);
		StopMusic();
		return (new SceneTitle);
	}

	void enemy();
	{
		m_EcountTimer++;
		if (m_EcountTimer >= 150)
		{
			if (m_EcountTimer % 60 == 0)
			{
				m_ePos.x += 30.0f;
			}
		}
	}

	if (m_pos.x == Game::kScreenWidth / 2 - 10)
	{
		PlaySoundFile("SE/BAN.mp3", DX_PLAYTYPE_BACK);
	}

	return this;
}


void SceneErrorMain::draw()
{
	if (true)
	{
		SetFontSize(64);

		DrawString(240, 200, "3", GetColor(255, 0, 0));
		m_countTimer++;

		if (m_countTimer > 50)
		{
			DrawString(280, 200, "2", GetColor(255, 0, 0));

			if (m_countTimer > 100)
			{
				DrawString(320, 200, "1...", GetColor(255, 0, 0));

				if (m_countTimer > 150)
				{

					//DrawGraph(0, 0, m_handle, TRUE);
					DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), true);
					
					if (m_pos.x >= Game::kScreenWidth / 2 - 10)
					{
						DrawGraph(0, 0, m_handle, true);
						
					}

					//SetFontSize(32);
					//DrawString(0, 0, "ƒŒƒxƒ‹1", GetColor(0, 255, 255));
					//DrawLine(GoalLineX, GoalLineY, GoalLineX, 480, GetColor(255, 0, 255), 20);
					DrawGraph(m_pos.x, m_pos.y, m_Phandle, TRUE);
					DrawTurnGraph(m_ePos.x, m_ePos.y, m_Ehandle, TRUE);

				}
			}
		}
	}
}
