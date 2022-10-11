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
	m_vec.x = 5.0f;
	m_vec.y = .0f;
}

void player::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_2)
	{
		if (padState & PAD_INPUT_2)
		{
			m_pos.x += 0.1f;

		}
	}

}

void player::draw()
{
	DrawCircle(m_pos.x, m_pos.y, 20, GetColor(255, 255, 255), true);
}