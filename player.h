#pragma once
#include "Vec2.h"

class player
{
public:
	player();
	virtual ~player();
	
	void init();
	void update();
	void draw();

private:

	Vec2 m_pos;
	Vec2 m_vec;

};