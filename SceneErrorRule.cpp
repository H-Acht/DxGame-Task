#include "DxLib.h"
#include "SceneErrorRule.h"
#include "SceneErrorMain.h"

void SceneErrorRule::init()
{
	m_textPosX = 160;
	m_textPosY = 220;
}

SceneBase* SceneErrorRule::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		return(new SceneErrorMain);
	}


	return this;
}

void SceneErrorRule::draw()
{
	DrawString(90, m_textPosY - 160, "ZとX、又はAとBを�?", GetColor(255, 0, 0));
	DrawString(90, m_textPosY - 96, "下�?敵よりも�?にゴ", GetColor(255, 0, 0));

	DrawString(m_textPosX, m_textPosY, "レベル1:<��>", GetColor(255, 0, 0));
	DrawString(m_textPosX, m_textPosY + 32, "レベル2:<��>", GetColor(255, 0, 0));
	DrawString(m_textPosX, m_textPosY + 64, "レベル3:<Z or A>", GetColor(255, 0, 0));
	DrawString(m_textPosX, m_textPosY + 96, "タイトルに戻�:<��>", GetColor(255, 0, 0));

}