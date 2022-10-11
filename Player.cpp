#include "player.h"
#include "DxLib.h"

namespace
{
	constexpr float kSpeed = 5.0f;
}

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
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
}

void player::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_UP)
	{
		m_pos.y -= kSpeed;
	}
	else if (padState & PAD_INPUT_DOWN)
	{
		m_pos.y += kSpeed;
	}
	else if (padState & PAD_INPUT_LEFT)
	{
		m_pos.x -= kSpeed;
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		m_pos.x += kSpeed;
	}
	else
	{

	}

}

void player::draw()
{
	DrawCircle(m_pos.x, m_pos.y, 20, GetColor(255, 255, 255), true);
}