#include "DxLib.h"

#include "game.h"
#include "SceneTitle.h"
#include "SceneMain.h"

void SceneTitle::init()
{
	m_textPosX = Game::kScreenWidth / 2 -50;
	m_textPosY = Game::kScreenHeight / 2;

	m_isEnd = false;
}

SceneBase* SceneTitle::update()
{
	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_DOWN)
	{
		
	}
	
	return this;
}

void SceneTitle::draw()
{
	DrawString(m_textPosX, m_textPosY, "ƒ^ƒCƒgƒ‹‰æ–Ê", GetColor(255, 255, 255));
}