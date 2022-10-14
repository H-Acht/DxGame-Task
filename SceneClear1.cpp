#include "DxLib.h"
#include "SceneClear1.h"
#include "SceneTitle.h"


void SceneClear1::init()
{
	m_textPosX = 140;
	m_textPosY = 220;
}

SceneBase* SceneClear1::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_3)
	{
		return (new SceneTitle);
	}

	return this;
}

void SceneClear1::draw()
{
	DrawString(m_textPosX +130, m_textPosY - 100, "Lv.1 CLEAR!!", GetColor(255, 255, 255));
	DrawString(m_textPosX-110, m_textPosY, "Pless C Key or X to Back to Title", GetColor(255, 255, 255));

}