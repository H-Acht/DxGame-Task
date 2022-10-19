#include "DxLib.h"
#include "SceneClear2.h"
#include "SceneTitle.h"
#include "SceneMainLevel3.h"

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
		return (new SceneMainLevel3);
	}
	else if (padState & PAD_INPUT_4)
	{
		return (new SceneTitle);
	}

	return this;
}

void SceneClear2::draw()
{
	DrawString(m_textPosX + 72, m_textPosY - 100, "Lv.2 CLEAR!!", GetColor(192, 192, 192));
	DrawString(m_textPosX - 85, m_textPosY, "Pless [X] to Go to Next Level!", GetColor(255, 255, 255));
	DrawString(m_textPosX - 45, m_textPosY + 100, "Pless [Y] to Back to Title", GetColor(255, 255, 255));
}