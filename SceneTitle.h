#pragma once
#include "SceneBase.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle()
	{
		m_textPosX = 0;
		m_textPosY = 0;
		m_isEnd = false;
	}
	virtual ~SceneTitle() {}


	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;

	virtual bool isEnd() { return m_isEnd; }
private:
	// テキスト表示位置変更
	int m_textPosX;
	int m_textPosY;
	
	bool m_isEnd;
};