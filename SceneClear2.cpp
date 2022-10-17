#include "DxLib.h"
#include "SceneClear2.h"
#include "SceneTitle.h"


void SceneClear2::init()
{
	m_textPosX = 140;
	m_textPosY = 220;
}

SceneBase* SceneClear2::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_3)
	{
		return (new SceneTitle);
	}

	return this;
}

void SceneClear2::draw()
{
	DrawString(m_textPosX + 75, m_textPosY - 100, "Lv.2 CLEAR!!", GetColor(255, 255, 255));
	DrawString(m_textPosX - 110, m_textPosY, "Pless C Key or X to Back to Title", GetColor(255, 255, 255));
}