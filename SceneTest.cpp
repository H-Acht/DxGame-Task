#include "DxLib.h"
#include "SceneMain.h"
#include "SceneTest.h"
#include "SceneTitle.h"

void SceneTest::init()
{
	m_textPosX = 0;
	m_textPosY = 0;
	//m_textVecX = 4;
	//m_textVecY = 4;

	m_isEnd = false;
}

SceneBase* SceneTest::update()
{
	// 文字の移動
	/*m_textPosX += m_textVecX;
	m_textPosY += m_textVecY;
	if (m_textPosX < 0)
	{
		m_textPosX = 0;
		m_textVecX = 4;
	}
	if (m_textPosX > 200)
	{
		m_textPosX = 200;
		m_textVecX = -4;
	}
	if (m_textPosY < 0)
	{
		m_textPosY = 0;
		m_textVecY = 4;
	}
	if (m_textPosY > 200)
	{
		m_textPosY = 200;
		m_textVecY = -4;
	}*/

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_1)
	{
		DrawString(m_textPosX, m_textPosY+100, "テスト", GetColor(255, 255, 255));


		//PlaySoundFile("sound/cursor1.mp3", DX_PLAYTYPE_LOOP);

		//PlaySoundFile("sound/cursor5.mp3", DX_PLAYTYPE_NORMAL);

	}

	if (padState & PAD_INPUT_3)
	{
		return (new SceneTitle);
	}

	return this;
}

void SceneTest::draw()
{
	DrawString(m_textPosX, m_textPosY, "テスト画面", GetColor(255, 255, 255));
}