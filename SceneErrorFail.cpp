#include "Dxlib.h"
#include "game.h"
#include "SceneErrorFail.h"
#include "SceneTitle.h"

void SceneErrorFail::init()
{
	m_textPosX = 140;
	m_textPosY = Game::kScreenHeight / 2 -20;
}

SceneBase* SceneErrorFail::update()
{
	StopMusic();

	PlaySoundFile("SE/DEAD.wav", DX_PLAYTYPE_NORMAL);
	return (new SceneTitle);

	return this;
}

void SceneErrorFail::draw()
{
	SetFontSize(64);
	DrawString(m_textPosX, m_textPosY, "You are Die", GetColor(255, 0, 0));
}