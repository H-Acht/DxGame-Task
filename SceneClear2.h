#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneClear2 : public SceneBase
{
public:
	SceneClear2()
	{
		m_textPosX = 0;
		m_textPosY = 0;
	}
	virtual ~SceneClear2() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	int m_textPosX;
	int m_textPosY;
};