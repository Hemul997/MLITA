// Viruces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
const int MAX_SIZE = 50;
const int MIN_SIZE = 2;
const int MAX_COUNT_VIRUCES = 10;
const int MIN_COUNT_VIRUCES = 1;

using namespace std;

struct Virus {
	int x, y;
};
int main()
{
	int field[MAX_SIZE][MAX_SIZE];
	int sizeOfField;
	int countOfViruces;
	ifstream inputFile("input.txt");
	list<Virus> viruses;
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
	viruses.sort();
	cout << "Sorted list of coordinats viruses\n";
	for (auto it = viruses.begin(); it != viruses.end(); ++it)
	{
		cout << (*it).x << (*it).y << endl;
	}
	/*for (auto i = 0; i < sizeOfField; ++i)
	{
		for (auto j = 0; j < sizeOfField; ++j)
		{
			if
		}
	}*/
    return 0;
}

