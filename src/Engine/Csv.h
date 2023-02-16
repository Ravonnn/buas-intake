#pragma once
#include <fstream>
#include <iostream>
#include <string>



	void ReadCsv(std::string path) {
		std::ifstream myFile;
		myFile.open(path);
		std::string line;
		int n = 2;//desired row number
		int a = 0;//counter

		std::cout << path << std::endl;
		while (std::getline(myFile, line)) {
			a++;
			if (a == n) {
				std::cout << line << std::endl;
				break;
			}

		}
	}
