#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneRule : public SceneBase
{
public:
	SceneRule() 
	{
		m_textPosX = 0;
		m_textPosY = 0;
	}
	virtual ~SceneRule() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	int m_textPosX;
	int m_textPosY;
};