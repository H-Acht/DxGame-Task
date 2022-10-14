#pragma once
#include "SceneBase.h"

class SceneError : public SceneBase
{
public:
	SceneError() {}
	virtual ~SceneError() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	int m_textPosX;
	int m_textPosY;
};

