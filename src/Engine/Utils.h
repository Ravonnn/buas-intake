#pragma once
#include "../pch.h"

using namespace std;

namespace Celes {
	vector<string> StringSplit(string s, char del)
	{
		vector<string> splittedString;
		stringstream ss(s);
		string word;
		while (!ss.eof()) {
			getline(ss, word, del);
			splittedString.push_back(word);
		}

		return splittedString;
	}

}