// Kamni.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;
const int MAX_COUNT = 500;
const int MAX_SPECIFIED_WEIGHT = 50000;
const int MAX_WEIGHT = 100;
const int MIN = 1;

int main()
{
	int arrOfAttainability[MAX_WEIGHT];
	int Elements[MAX_COUNT];
	int numsOfElements[MAX_COUNT];
	int countOfStones, specifiedWeight;


	fstream inputFile("input.txt");
	inputFile >> countOfStones;
	inputFile >> specifiedWeight;
	if (countOfStones > MAX_COUNT || countOfStones < MIN || specifiedWeight < MIN || countOfStones > MAX_WEIGHT)
	{
		cout << "Error of input";
		return 1;
	}
	arrOfAttainability[0] = 0;
	Elements[0] = 0;
	for (auto i = 1; i <= specifiedWeight; ++i)
	{
		arrOfAttainability[i] = -1;
	}
	for (auto i = 1; i <= countOfStones; ++i)//Инициализация
	{	
		inputFile >> Elements[i];
	}
	for (auto i = 1; i <= countOfStones; ++i)
	{
		for (auto j = 0; j <= specifiedWeight; ++j)
		{
			if (arrOfAttainability[i] > j)
			{
				
			}
		}
	}
    return 0;
}

