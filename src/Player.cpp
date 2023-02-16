#include "Player.h"

namespace Celes {

	void Player::Draw(Surface* renderer)
	{
		m_Sprite->Draw(renderer, m_PositionX, m_PositionY);
	}

	void Player::Move(float x, float y)
	{
		m_PositionX = x;
		m_PositionY = y;
	}

}