#pragma once
#include "SceneBase.h"

class SceneErrorRule :	public SceneBase
{
public:
	SceneErrorRule() {}
	virtual ~SceneErrorRule() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	int m_textPosX;
	int m_textPosY;
};

