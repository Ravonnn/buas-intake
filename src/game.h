#pragma once

#include "pch.h"
#include "Engine/TileMap.h"
//#include "Player.h"

using std::shared_ptr;

namespace Celes {

	enum class GameState {
		MENU = 0,
		GAME = 1,
		DEAD = 2,
		TILEMAPEDITOR = 3
	};

class Surface;
class Game
{
public:
	void SetTarget( Surface* surface ) { m_Renderer = surface; }
	void Init();
	/*void OnEvent(float deltaTime);*/
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove( int x, int y ) { /* implement if you want to detect mouse movement */ }
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown(int key) {}
private:
	Surface* m_Renderer;
	TileMap* m_TileMap;

	GameState m_GameState = GameState::GAME;

	/*Player* m_Player;*/
};

}; // namespace Celes