#include "DxLib.h"
#include "game.h"
#include "SceneErrorMain.h"
#include "SceneErrorTitle.h"

namespace
{
	int kSpeed = 5.0f;
}

void SceneErrorMain::init()
{
	m_pos.x = 100.0f;
	m_pos.y = 120.0f;

	m_ePos.x = 100.0f;
	m_ePos.y = 300.0f;

	m_eVec.x = 0.0f;
	m_eVec.y = 0.0f;

	GoalLineX = 600;
	GoalLineY = 0;

	m_handle = LoadGraph("BG/background_A.jpg");
	m_Phandle = LoadGraph("CC/Snails_PP.png");
	m_Ehandle = LoadGraph("CC/Snails_AA.png");

	m_countTimer = 0;
	m_EcountTimer = 0;
}

SceneBase* SceneErrorMain::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	static int push = 0;

	if (padState & PAD_INPUT_UP)
	{
		m_pos.y -= kSpeed;
	}
	else if (padState & PAD_INPUT_DOWN)
	{
		m_pos.y += kSpeed;
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		m_pos.x += kSpeed;
	}
	else if (padState & PAD_INPUT_LEFT)
	{
		m_pos.x -= kSpeed;
	}

	if (padState & PAD_INPUT_3)
	{
		return (new SceneErrorTitle);
	}

	void enemy();
	{
		m_EcountTimer++;
		if (m_EcountTimer >= 150)
		{
			if (m_EcountTimer % 30)
			{
				m_eVec.x = m_pos.x;
				m_eVec.y = m_pos.y;

				m_ePos.x += m_eVec.x;
				m_ePos.y += m_eVec.y;
			}
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
					DrawGraph(0, 0, m_handle, TRUE);

					SetFontSize(32);
					DrawString(0, 0, "ƒŒƒxƒ‹1", GetColor(0, 255, 255));
					DrawLine(GoalLineX, GoalLineY, GoalLineX, 480, GetColor(255, 0, 255), 20);
					DrawGraph(m_pos.x, m_pos.y, m_Phandle, TRUE);
					DrawTurnGraph(m_ePos.x, m_ePos.y, m_Ehandle, TRUE);
				}
			}
		}
	}
}