#include "DxLib.h"
#include "SceneFail.h"
#include "SceneTitle.h"


void SceneFail::init()
{
	m_textPosX = 140;
	m_textPosY = 220;
}

SceneBase* SceneFail::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_4)
	{
		return (new SceneTitle);
	}

	return this;
}

void SceneFail::draw()
{
	DrawString(m_textPosX + 110, m_textPosY - 100, "Failure...", GetColor(255, 255, 255));
	DrawString(m_textPosX - 45, m_textPosY, "Pless [Y] to Back to Title", GetColor(255, 255, 255));
}