#include "DxLib.h"
#include "SceneClear3.h"
#include "SceneTitle.h"


void SceneClear3::init()
{
	m_textPosX = 140;
	m_textPosY = 220;
}

SceneBase* SceneClear3::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_3)
	{
		return (new SceneTitle);
	}

	return this;
}

void SceneClear3::draw()
{
	DrawString(m_textPosX + 130, m_textPosY - 100, "Lv.3 CLEAR!!", GetColor(255, 255, 255));
	DrawString(m_textPosX - 110, m_textPosY, "Pless C Key or X to Back to Title", GetColor(255, 255, 255));

}