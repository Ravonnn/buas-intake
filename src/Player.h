#pragma once

#include "PhysicsCollidable.h"
#include "Engine/surface.h"

namespace Celes {

	class Player : public PhysicsCollidable 
	{
	public:
		void Draw(Surface* renderer);
		void Move(float x, float y);
		void OnUpdate(float deltaTime);
		
	private:
		void Animate();
	private:
		Sprite* m_Sprite;
		float m_PositionX;
		float m_PositionY;
	};
}
