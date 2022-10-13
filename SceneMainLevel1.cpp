#include "DxLib.h"

#include "SceneMainLevel1.h"
#include "SceneTitle.h"
#include "SceneClear.h"
#include "SceneFail.h"

#include "game.h"


void SceneMain::init()
{
	m_textPosX = 0;
	m_pos.x = 100.0f;
	m_pos.y = Game::kScreenHeight / 2;

	m_ePos.x = 100.0f;
	m_ePos.y = 380.0f;

}

SceneBase* SceneMain::update()
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
	else if(padState & PAD_INPUT_2)
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

	if (m_pos.x >= 600)
	{
		return (new SceneClear);
	}

	void enemy();
	{
		m_ePos.x += 0.5;
		if (m_ePos.x >= 600)
		{
			return(new SceneFail);
		}
	}

	return this;
}

void SceneMain::draw()
{
	DrawString(m_textPosX, 0, "play", GetColor(255, 255, 255));
	DrawCircle(m_pos.x, m_pos.y, 20, GetColor(255, 0, 0), true);
	DrawCircle(m_ePos.x, m_ePos.y, 20, GetColor(0, 0, 255), true);
	DrawLine(600, 0, 600, 480, GetColor(255, 255, 0), 20);
}