// Viruces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
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
	int sizeOfField;
	int countOfViruces;
	ifstream inputFile("input.txt");
	vector<Virus> viruses;
	inputFile >> sizeOfField >> countOfViruces;

    return 0;
}

