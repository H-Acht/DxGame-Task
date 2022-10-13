#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneRule : public SceneBase
{
public:
	SceneRule() {}
	virtual ~SceneRule() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	int m_textPosX;
	int m_textPosY;
};