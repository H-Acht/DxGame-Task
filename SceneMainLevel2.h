#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneMainLevel2 : public SceneBase
{
public:
	SceneMainLevel2() {}
	virtual ~SceneMainLevel2() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
private:

	Vec2 m_pos;
	Vec2 m_ePos;

	int GoalLineX;
	int GoalLineY;
};