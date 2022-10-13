#include "DxLib.h"

#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneGoal.h"
#include "game.h"


void SceneMain::init()
{
	m_textPosX = 0;
	m_pos.x = 100.0f;
	m_pos.y = Game::kScreenHeight / 2;
}

SceneBase* SceneMain::update()
{	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	static int push = 0;

	if (padState & PAD_INPUT_2) 
	{
		if (push == 0) 
		{
			m_pos.x += 50.0f;
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

	if (m_pos.x >= 600)
	{
		return (new SceneGoal);
	}

	

	return this;
}

void SceneMain::draw()
{
	DrawString(m_textPosX, 0, "play", GetColor(255, 255, 255));
	DrawCircle(m_pos.x, m_pos.y, 20, GetColor(255, 255, 255), true);
	DrawLine(600, 0, 600, 480, GetColor(255, 255, 0), 20);
}