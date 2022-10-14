#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneClear1 : public SceneBase
{
public:
	SceneClear1() {}
	virtual ~SceneClear1() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	int m_textPosX;
	int m_textPosY;
};