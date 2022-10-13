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
	if (padState & PAD_INPUT_1)
	{
		return (new SceneMain);
	}
	
	return this;
}

void SceneTitle::draw()
{
	SetFontSize(64);

	DrawString(m_textPosX-110, m_textPosY-100, "R E N D A", GetColor(255, 255, 255));
	
	SetFontSize(32);

	DrawString(m_textPosX-63, m_textPosY +10, "Pless Z Key", GetColor(255, 255, 255));

}