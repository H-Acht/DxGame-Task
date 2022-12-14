#include "SceneError.h"
#include "SceneErrorTitle.h"
#include "DxLib.h"
void SceneError::init()
{
	StopMusic();
	PlayMusic("BGM/ErrorSiren.mp3", DX_PLAYTYPE_BACK);
	m_textPosX = -100;
	m_textPosY = 120;

	m_countTimer = 0;
}

SceneBase* SceneError::update()
{
	m_countTimer++;
	if (m_countTimer >= 250)
	{
		return(new SceneErrorTitle);
	}

	return this;
}

void SceneError::draw()
{
	SetFontSize(64);
	DrawString(m_textPosX -=5.0f, m_textPosY, "ERROR!!error!!ERROR!!error!!ERROR!!error!!ERROR!!error!!ERROR!!error!!ERROR!!error!!ERROR!!error!", GetColor(255, 0, 0));
	SetFontSize(32);
	DrawString(165, m_textPosY + 200, "タイトルに戻ります", GetColor(255, 255, 255));
}
