#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneGoal : public SceneBase
{
public:
	SceneGoal() {}
	virtual ~SceneGoal() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	int m_textPosX;
	int m_textPosY;
};