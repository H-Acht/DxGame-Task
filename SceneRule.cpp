#include "DxLib.h"
#include "SceneRule.h"
#include "SceneTitle.h"


void SceneRule::init()
{
	m_textPosX = 140;
	m_textPosY = 220;

}

SceneBase* SceneRule::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_DOWN)
	{
		return (new SceneTitle);
	}

	return this;
}

void SceneRule::draw()
{
	DrawString(m_textPosX, m_textPosY, "òAë≈ÅBÇΩÇæÇªÇÍÇæÇØ", GetColor(255, 255, 255));
}