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
		return (new SceneTitle);
	}
	else if (padState & PAD_INPUT_4)
	{
		return (new SceneMainLevel2);
	}

	return this;
}

void SceneClear1::draw()
{
	DrawString(m_textPosX +75, m_textPosY - 100, "Lv.1 CLEAR!!", GetColor(255, 255, 255));
	DrawString(m_textPosX-70, m_textPosY, "Pless X to Back to Title", GetColor(255, 255, 255));
	DrawString(m_textPosX - 70, m_textPosY+100, "Pless Y to Go to Next Level!", GetColor(255, 255, 255));

}