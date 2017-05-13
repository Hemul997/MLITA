// Lines.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
const unsigned int MAX_COUNT_OF_LINES = static_cast<unsigned int>(5 * pow(10, 5));
const unsigned int MIN_COUNT_OF_LINES = 1;
const int MIN_LEFT_POINT = static_cast<int>(pow(-10, 9));
const int MAX_RIGHT_POINT = static_cast<int>(pow(10, 9));
//struct Point
//{
//	int x;
//	char position;
//};
typedef multimap<int, char> Points;
bool ReadPointsFromFile(ifstream &input, unsigned int countLines, Points &points)
{
	for (unsigned int it = 0; it < countLines; ++it)
	{
		
		int x1, x2;
		/*Point point1, point2;*/
		input >> x1 >> x2;
		if (x1 > x2 || x1 < MIN_LEFT_POINT || x2 > MAX_RIGHT_POINT || (it < countLines && input.eof()))
			return false;
		else
		{
			/*point1.position = 'l';
			point2.position = 'r';
			point1.x = x1;
			point2.x = x2;
			points.push_back(point1);
			points.push_back(point2);*/
			points.emplace(pair<int, char>(x1, 'l'));
			points.emplace(pair<int, char>(x2, 'r'));
		}
	}
	return true;
}
int main()
{
	ifstream inputFile("input.txt");
	unsigned int countLines = 0;
	ofstream outputFile("output.txt");
	if (!inputFile.is_open())
	{
		outputFile << "Failed to open " << "input.txt" << " for reading\n";
		return 1;
	}
	inputFile >> countLines;
	if (countLines < MIN_COUNT_OF_LINES || countLines > MAX_COUNT_OF_LINES)
	{
		cout << "Wrong count of lines\n";
		return 1;
	}
	/*vector<Point> pointsOfLines;*/
	Points pointsOfLines;
	if (!ReadPointsFromFile(inputFile, countLines, pointsOfLines))
	{
		cout << "Error of reading points\n";
		return 1;
	}
	for (auto it : pointsOfLines)
	{
		cout << it.first << ' ' << it.second << endl;
	}
    return 0;
}

