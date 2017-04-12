// PairsOfDisciplines.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

const int ARGUMENT_COUNT;


int main(int argc, char * argv[])
{
	int countOFDisciplines, firstDiscipline, secondDiscipline;
	if (argc != ARGUMENT_COUNT)
	{
		cout << "Invalid parameters count\n"
			 << "Use PairsOfDisciplines.exe <input file> <output file>\n";
	}
	ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}
	ofstream outputFile(argv[2]);
	if (!outputFile.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing" << endl;
		return 1;
	}

    return 0;
}

