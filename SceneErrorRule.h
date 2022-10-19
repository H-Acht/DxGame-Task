#pragma once
#include "SceneBase.h"

class SceneErrorRule :	public SceneBase
{
public:
	SceneErrorRule()
	{
		m_textPosX = 0;
		m_textPosY = 0;
		Color1 = 0;
		Color2 = 0;
	}
	virtual ~SceneErrorRule() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	int m_textPosX;
	int m_textPosY;

	int Color1;
	int Color2;
};

