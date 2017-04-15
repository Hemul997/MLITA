// Rabin-Carp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int NUMERATOR = 52;
const int DENOMENATOR = 65713;

int numberInitialization(size_t searchStrSize)//проверка на входной хэш
{
	int number = 1;
	for (auto i = 0; i < searchStrSize; ++i)
	{
		number = (number*NUMERATOR) % DENOMENATOR;
	}
	return number;
}
int ringHash(string searchString, size_t searchStrSize, int prevHash, int number)
{
	if (number == 0)
	{
		number = numberInitialization(searchStrSize);
	}
	if (prevHash == 0)
	{
		for (auto i = 0; i < searchStrSize; ++i)
		{
			prevHash = (prevHash*NUMERATOR + (int)searchString[i]) % DENOMENATOR;
		}
		return prevHash;
	}
	else
	{
		int hash;
		if (hash < 0) 
		{
			hash += DENOMENATOR;
		}
		return hash;
	}
}
int main()
{
	string searchString, inputText; // входные данные

	
    return 0;
}

