// Remont.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>

const int i = 10000;

using namespace std;
struct Line
{
	int left;
	int right;
};
bool IncorrectCoordinats(int left, int right);
int main()
{
	int countOfOtr;
	int countOfMasters;
	int counter;
	ifstream input("input.txt");
	ofstream output("output.txt");
	vector<Line> linesOfRoads;
	char Coord[i];
	char rightCoord[i];
	input >> countOfOtr;
	input >> countOfMasters;
	int left;
	int right;
	while ((input >> left) && (input >> right))
	{
		if (!IncorrectCoordinats(left, right))
		{
			Line line;
			line.left = left;
			line.right = right;
			linesOfRoads.push_back(line);
		}
	}
	for (auto it = linesOfRoads.begin(); it != linesOfRoads.end(); ++it)
	{
		cout << (*it).left << " " << (*it).right << endl;
	}

    return 0;
}
bool IncorrectCoordinats(int left, int right)
{
	return(left > right || left == right);
}
