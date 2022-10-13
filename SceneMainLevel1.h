#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneMainLevel1 : public SceneBase
{
public:
	SceneMainLevel1() {}
	virtual ~SceneMainLevel1() {}

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