#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneErrorMain :	public SceneBase
{
public:
	SceneErrorMain() {}
	virtual ~SceneErrorMain() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
private:

	Vec2 m_pos;
	Vec2 m_ePos;

	int GoalLineX;
	int GoalLineY;

	int m_handle;
	int m_Phandle;
	int m_Ehandle;

	int m_countTimer;
	int m_EcountTimer;

};

