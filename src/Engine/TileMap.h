#pragma once
#include "../pch.h"


namespace Celes {

	class TileMap
	{
	public:
		TileMap(Surface* renderer);
		~TileMap();

		void LoadMap(std::string locationMap, Surface* spriteSheet);
		void DrawMap(uint scale);
	private:
		void LoadCsv(std::string path);
		void DrawTile(uint positionX, uint positionY, uint x, uint y, uint size);
		void TranslateCsvMap();
	private:
		Surface* m_Renderer;
		Surface* m_TileSet;
		uint m_tileSetWidth;

		Surface* m_Terrain;
		Surface* m_Cliff;

		std::vector<std::string> m_CsvMap;
		std::vector<std::vector<std::string>> m_CsvVec;
		std::vector<Pixel*> m_PixelVec;
		uint m_Width = 5;
		uint m_Height = 5;
	};
}