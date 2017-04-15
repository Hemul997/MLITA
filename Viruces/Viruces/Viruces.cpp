// Viruces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>

const int MAX_SIZE = 50;
const int MIN_SIZE = 2;
const int MAX_COUNT_VIRUCES = 10;
const int MIN_COUNT_VIRUCES = 1;

typedef int field[MAX_SIZE][MAX_SIZE];
using namespace std;

struct Virus {
	int x, y;
};
void pushTheViruses(int sizeOfField, field workField, int x, int y);
int main()
{
	field workField;
	int sizeOfField;
	int countOfViruces;
	ifstream inputFile("input.txt");
	list<Virus> viruses;
	int top = 0;
	inputFile >> sizeOfField >> countOfViruces;
	if (sizeOfField < MIN_SIZE || sizeOfField > MAX_SIZE || countOfViruces > MAX_COUNT_VIRUCES || countOfViruces < MIN_COUNT_VIRUCES)
	{
		cout << "Input error!\n";
		return 1;
	}
	for (auto i = 0; i < countOfViruces; ++i)
	{
		Virus virus;
		inputFile >> virus.x >> virus.y;
		viruses.push_back(virus);
	}
	for (auto it = viruses.begin(); it != viruses.end(); ++it)
	{
		pushTheViruses(sizeOfField, workField, (*it).x, (*it).y);
	}
	for (auto i = 1; i <= sizeOfField; ++i)
	{
		for (auto j = 1; j <= sizeOfField; ++j)
		{
			cout << workField[i][j] << ' ';
		}
		cout << endl;
	}
	for (auto i = 1; i <= sizeOfField; ++i)
	{
		for (auto j = 1; j <= sizeOfField; ++j)
		{
			if (workField[i][j] == 0)
			{

			}
		}
	}
	cout << top << endl;
    return 0;
}

void pushTheViruses(int sizeOfField, field workField, int x, int y)
{
	for (auto i = 1; i <= sizeOfField; ++i)
	{
		for (auto j = 1; j <= sizeOfField; ++j)
		{
			if (i == x && j == y)
			{
				workField[i][j] = 0;
			}
			else
			{
				if (workField[i][j] != 0)
				{
					workField[i][j] = -1;
				}
			}
		}
	}
}