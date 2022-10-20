#include "DxLib.h"

#include "game.h"
#include "SceneTitle.h"
#include "SceneRule.h"


void SceneTitle::init()
{
	PlayMusic("BGM/HIRAHIRA.mp3", DX_PLAYTYPE_LOOP);

	m_textPosX = Game::kScreenWidth / 2 -50;
	m_textPosY = Game::kScreenHeight / 2;

	m_isEnd = false;
}

SceneBase* SceneTitle::update()
{
	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_UP)
	{
		return (new SceneRule);
	}
	
	return this;
}

void SceneTitle::draw()
{
	SetFontSize(64);

	DrawString(m_textPosX-110, m_textPosY-100, "R E N D A", GetColor(255, 255, 255));
	
	SetFontSize(32);

	DrawString(m_textPosX-150, m_textPosY - 20, "�`�A�ŁB�������ꂾ���`", GetColor(255, 255, 255));
	DrawString(m_textPosX-50, m_textPosY +50, "Pless <��>", GetColor(255, 255, 255));

}