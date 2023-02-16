#include "TileMap.h"
#include "Utils.h"

namespace Celes {

	TileMap::TileMap(Surface* renderer) : m_Renderer(renderer)
	{
	
	}

	TileMap::~TileMap()
	{

	}

	void TileMap::LoadMap(std::string locationMap, Surface* spriteSheet)
	{
		m_TileSet = spriteSheet;
		m_tileSetWidth = spriteSheet->GetWidth();
		LoadCsv("map.csv");
	}

	void TileMap::DrawMap(uint scale)
	{
		for (int y = 0; y < m_Height; y++)
			for (int x = 0; x < m_Width; x++)
			{
				std::string currentString = m_CsvVec.at(y).at(x);
				if (currentString == "BG") {
					DrawTile(0, 0, x, y, 32);
				}
				else if (currentString == "CF") {
					DrawTile(1, 0, x, y, 32);
				}
			}
	}

	void TileMap::LoadCsv(std::string path)
	{
		std::ifstream myFile;
		myFile.open(path);
		std::string line;

		m_CsvMap.resize(myFile.gcount());

		while (std::getline(myFile, line)) {
			m_CsvMap.push_back(line);
		}

		TranslateCsvMap();
	}

	void TileMap::DrawTile(uint positionX, uint positionY, uint x, uint y, uint size)
	{
		Pixel* src = m_TileSet->GetBuffer() + 1 + (positionX * (size + 1)) + ((1 + positionY * (size + 1)) * 595);
		m_PixelVec.push_back(src);
		Pixel* dst = m_Renderer->GetBuffer() + (x * size) + y * size * m_Renderer->GetWidth();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				dst[j] = src[j];
			src += m_tileSetWidth, dst += m_Renderer->GetWidth();
		}
	}

	void TileMap::TranslateCsvMap()
	{
		for (int i = 0; i < m_CsvMap.size(); i++) {
			std::string line = m_CsvMap.at(i);
			vector<std::string> splittedString = StringSplit(line, ',');
			
			m_CsvVec.push_back(splittedString);
		}
	}

}