#include "DxLib.h"
#include "SceneClear1.h"
#include "SceneTitle.h"
#include "SceneMainLevel2.h"

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
		return (new SceneMainLevel2);
	}
	else if (padState & PAD_INPUT_4)
	{
		return (new SceneTitle);
	}

	return this;
}

void SceneClear1::draw()
{
	DrawString(m_textPosX +72, m_textPosY - 100, "Lv.1 CLEAR!!", GetColor(196, 112, 34));
	DrawString(m_textPosX - 85, m_textPosY, "Pless [X] to Go to Next Level!", GetColor(255, 255, 255));
	DrawString(m_textPosX-45, m_textPosY+100, "Pless [Y] to Back to Title", GetColor(255, 255, 255));
}