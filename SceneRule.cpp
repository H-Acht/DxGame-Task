#include "DxLib.h"
#include "SceneRule.h"
#include "SceneTitle.h"
#include "SceneMainLevel1.h"
#include "SceneMainLevel2.h"
#include "SceneMainLevel3.h"

void SceneRule::init()
{
	m_textPosX = 160;
	m_textPosY = 220;
}

SceneBase* SceneRule::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_LEFT)
	{
		return (new SceneMainLevel1);
	}
	if (padState & PAD_INPUT_RIGHT)
	{
		return (new SceneMainLevel2);
	}
	if (padState & PAD_INPUT_1)
	{
		return (new SceneMainLevel3);
	}

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