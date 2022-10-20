#include "DxLib.h"

#include "game.h"
#include "SceneErrorTitle.h"
#include "SceneErrorRule.h"


void SceneErrorTitle::init()
{
	PlayMusic("BGM/noise.mp3", DX_PLAYTYPE_LOOP);
	
	m_textPosX = Game::kScreenWidth / 2 - 50;
	m_textPosY = Game::kScreenHeight / 2;

	m_isEnd = false;
}

SceneBase* SceneErrorTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_UP)
	{
		
		return (new SceneErrorRule);
	}

	return this;
}

void SceneErrorTitle::draw()
{

	SetFontSize(64);

	DrawString(m_textPosX - 50, m_textPosY - 100, "ÈÄ£Êâ", GetColor(255, 0, 0));

	SetFontSize(32);

	DrawString(m_textPosX -220, m_textPosY - 20, "?ûÈ?£Êâì„?Ç„Åü„Å?„Åù„Çå„Å?„ÅëÔΩ", GetColor(255, 0, 0));
	DrawString(m_textPosX - 70, m_textPosY + 50, "Pless UP Key", GetColor(255, 0, 0));

}