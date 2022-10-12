#include "player.h"
#include "DxLib.h"

player::player()
{

}

player::~player()
{

}

void player::init()
{
	m_pos.x = 100.0f;
	m_pos.y = 100.0f;
}

void player::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	
	static int push = 0;

	if (padState & PAD_INPUT_1)
	{
		if (push == 0)
		{
			m_pos.x += 1.0f;
		}
		push = 1;
	}
	else if (padState & PAD_INPUT_2)
	{
		if (push == 0)
		{
			m_pos.x += 1.0f;
		}
		push = 1;
	}
	else
	{
		push = 0;
	}
}

void player::draw()
{
	DrawCircle(m_pos.x, m_pos.y, 20, GetColor(255, 255, 255), true);
}