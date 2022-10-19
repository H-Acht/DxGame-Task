#pragma once
#include "SceneBase.h"

class SceneError : public SceneBase
{
public:
	SceneError() 
	{
		m_textPosX = 0;
		m_textPosY = 0;
		m_countTimer = 0;
	}
	virtual ~SceneError() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	int m_textPosX;
	int m_textPosY;
	int m_countTimer;
};

