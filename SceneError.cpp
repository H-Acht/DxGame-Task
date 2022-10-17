#include "SceneError.h"
#include "SceneErrorTitle.h"
#include "DxLib.h"
void SceneError::init()
{
	m_textPosX = -30;
	m_textPosY = 120;

	m_countTimer = 0;
}

SceneBase* SceneError::update()
{
	m_countTimer++;
	if (m_countTimer >= 100)
	{
		return(new SceneErrorTitle);
	}

	return this;
}

void SceneError::draw()
{
	DrawString(m_textPosX, m_textPosY, "ERROR!!error!!ERROR!!error!!ERROR!!error!!ERROR!!error!!ERROR!!error!!ERROR!!error!!ERROR!!error!!ERROR!!", GetColor(255, 0, 0));
	DrawString(m_textPosX + 195, m_textPosY + 200, "ƒ^ƒCƒgƒ‹‚É–ß‚è‚Ü‚·", GetColor(255, 255, 255));

}
