// Positions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>

using namespace std;

void FindPositions(fstream & output, unsigned int x, unsigned int y)
{
	output << ((0 == x % 2 || 0 == y % 2) ? 1 : 2) << endl;
}
int main()
{
	fstream input("input.txt"), output("output.txt");
	unsigned int amountOfGames = 0, x = 0, y = 0;
	input >> amountOfGames;
	for (unsigned int it = 0; it < amountOfGames; ++it)
	{
		input >> x >> y;
		FindPositions(output, x, y);
	}
    return 0;
}

