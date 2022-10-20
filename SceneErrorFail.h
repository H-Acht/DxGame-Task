#pragma once
#include "SceneBase.h"

class SceneErrorFail :	public SceneBase
{
public:
	SceneErrorFail()
	{
		m_textPosX = 0;
		m_textPosY = 0;
	}
	virtual ~SceneErrorFail() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	int m_textPosX;
	int m_textPosY;
};

