#include "DxLib.h"
#include "game.h"
#include "SceneErrorMain.h"
#include "SceneTitle.h"
#include "SceneErrorFail.h"

void SceneErrorMain::init()
{
	m_pos.x = 100.0f;
	m_pos.y = 200.0f;

	m_ePos.x = -330.0f;
	m_ePos.y = 100.0f;

	GoalLineX = 600;
	GoalLineY = 0;

	m_handle = LoadGraph("BG/te.jpg");
	m_Phandle = LoadGraph("CC/Snails_Sad.png");
	m_Ehandle = LoadGraph("CC/creature.png");

	m_countTimer = 0;
	m_EcountTimer = 0;
}

SceneBase* SceneErrorMain::update()
{
	m_EcountTimer++;
	if (m_EcountTimer >= 150)
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

		if (padState & PAD_INPUT_4)
		{
			PlaySoundFile("SE/warai.wav", DX_PLAYTYPE_BACK);
		}

		if (m_pos.x >= GoalLineX)
		{
			DeleteGraph(m_handle);
			DeleteGraph(m_Phandle);
			DeleteGraph(m_Ehandle);
			StopMusic();
			return (new SceneTitle);
		}

		if (m_ePos.x + 350 >= m_pos.x)
		{
			return (new SceneErrorFail);
		}

		void enemy();
		{
			if (m_EcountTimer % 60 == 0)
			{
				m_ePos.x += 60.0f;
			}
		}

		if (m_pos.x == Game::kScreenWidth / 2 - 10)
		{
			PlaySoundFile("SE/BAN.mp3", DX_PLAYTYPE_BACK);
		}
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
					DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), true);
					
					if (m_pos.x >= Game::kScreenWidth / 2 - 10)
					{
						DrawGraph(0, 0, m_handle, true);
						
					}
					DrawTurnGraph(m_pos.x, m_pos.y, m_Phandle, TRUE);
					DrawTurnGraph(m_ePos.x, m_ePos.y, m_Ehandle, TRUE);
				}
			}
		}
	}
}
