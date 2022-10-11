#pragma once
#include "SceneBase.h"

class SceneMain : public SceneBase
{
public:
	SceneMain()
	{
		m_textPosX = 0;
		m_textVecX = 0;
	}
	virtual ~SceneMain() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	// テキスト表示位置変更
	int m_textPosX;
	int m_textVecX;
};