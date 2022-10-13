#include "DxLib.h"
#include "SceneClear.h"
#include "SceneTitle.h"


void SceneClear::init()
{
	m_textPosX = 140;
	m_textPosY = 220;

}

SceneBase* SceneClear::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_3)
	{
		return (new SceneTitle);
	}

	return this;
}

void SceneClear::draw()
{
	DrawString(m_textPosX +130, m_textPosY - 100, "Clear!!", GetColor(255, 255, 255));

	DrawString(m_textPosX-30, m_textPosY, "Pless C to Back to Title", GetColor(255, 255, 255));
}