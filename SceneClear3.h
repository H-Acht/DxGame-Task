#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneClear3 : public SceneBase
{
public:
	SceneClear3() 
	{
		m_textPosX = 0;
		m_textPosY = 0;
	}
	virtual ~SceneClear3() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	int m_textPosX;
	int m_textPosY;
};