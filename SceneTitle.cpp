#include "DxLib.h"

#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneTest.h"

void SceneTitle::init()
{
	m_textPosX = 570;
	m_textPosY = 300;

	m_isEnd = false;
}

SceneBase* SceneTitle::update()
{
	// 文字の移動
	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		// Mainに切り替え
		return(new SceneMain);
	}
	else if (padState & PAD_INPUT_2)
	{
		// Testに切り替え
		return (new SceneTest);
	}
	return this;
}

void SceneTitle::draw()
{
	DrawString(m_textPosX, m_textPosY, "タイトル画面", GetColor(255, 255, 255));
}