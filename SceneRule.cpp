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
	DrawString(160, m_textPosY - 160, "AとB連打で進むべし。", GetColor(255, 255, 255));
	DrawString(55, m_textPosY - 96, "下の敵よりも先にゴールを超えろ！", GetColor(255, 255, 255));

	DrawString(m_textPosX + 30, m_textPosY, "レベル1:<←>", GetColor(255, 255, 255));
	DrawString(m_textPosX + 30, m_textPosY + 32, "レベル2:<→>", GetColor(255, 255, 255));
	DrawString(m_textPosX + 30, m_textPosY + 64, "レベル3:<A>", GetColor(255, 255, 255));
	DrawString(m_textPosX + 30, m_textPosY + 96, "タイトルに戻る:<↓>", GetColor(255, 255, 255));

}