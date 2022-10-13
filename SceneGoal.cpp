#include "DxLib.h"
#include "SceneGoal.h"
#include "SceneTitle.h"


void SceneGoal::init()
{
	m_textPosX = 280;
	m_textPosY = 220;

}

SceneBase* SceneGoal::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_3)
	{
		return (new SceneTitle);
	}

	return this;
}

void SceneGoal::draw()
{
	DrawString(m_textPosX, m_textPosY, "Pless C to Back to Title", GetColor(255, 255, 255));
}