#include "game.h"


namespace Celes
{

	Surface* spriteSheet = new Surface("assets/nc2tiles.png");
	
	/*Sprite playerIdle(new Surface("assets/PlayerIdle"), 8);*/

	void Game::Init()
	{

		m_TileMap = new TileMap(m_Renderer);
		m_TileMap->LoadMap("first-level.csv", spriteSheet);
		/*m_Player = new Player();*/
	}

	void Game::Shutdown()
	{
	}

	void Game::Tick(float deltaTime)
	{
		// clear the graphics window

		switch (m_GameState)
		{
		case Celes::GameState::MENU:
			break;
		case Celes::GameState::GAME:
			break;
		case Celes::GameState::DEAD:
			break;
		case Celes::GameState::TILEMAPEDITOR:
			break;
		default:
			break;
		}

		m_Renderer->Clear(0);
		m_TileMap->DrawMap(2);
		/*m_Player->OnUpdate(deltaTime);

		m_Player->Draw(m_Renderer);*/
	}
}