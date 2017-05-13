// Rabin-Carp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <clocale>
#include <set>

using namespace std;


const int NUMERATOR = 52;
const unsigned long long DENOMENATOR = static_cast<unsigned long long>(pow(2, 1e56));

struct Rows
{
	int numOfRow;
	long long numOfRowEnd;
};
unsigned long long findAcceleratingCoeff(unsigned int m)
{
	unsigned long long h = 1;

	for (long long i = 1; i < m; ++i)
	{
		h *= NUMERATOR % DENOMENATOR;
	}
	return h;

}
bool compareStrings(const string & inputText, const string & searchString, unsigned int pos) 
{
	for (size_t i = 0; i < searchString.size(); ++i)
	{
		if (inputText[i + pos] != searchString[i])
		{
			return false;
		}
	}
	return true;
}
long long countHash(long long &prevHash, const char &symb)
{
	return((prevHash * NUMERATOR + symb) % DENOMENATOR);
}
bool RabinKarpSearch(set<unsigned int> &positions, const string & inputText, const string & searchString) 
{
	long long searchStringHash = 0, textBoxHash = 0;
	unsigned int inputTextSize = static_cast<unsigned int>(inputText.size()), searchStringSize = static_cast<unsigned int>(searchString.size());
	unsigned long long acceleratingCoeff(findAcceleratingCoeff(searchStringSize));

	for (long long i = 0; i < searchStringSize; ++i) 
	{
		searchStringHash = countHash(searchStringHash, searchString[i]);
		textBoxHash = countHash(textBoxHash, inputText[i]);
	}

	for (unsigned int pos = 0; pos <= inputTextSize - searchStringSize; ++pos)
	{
		if (searchStringHash == textBoxHash && compareStrings(inputText, searchString, pos))
		{
			positions.emplace(pos + 1);
		}
		long long prevTextBoxHash = textBoxHash - inputText[pos] * acceleratingCoeff;
		textBoxHash = countHash(prevTextBoxHash, inputText[pos + searchStringSize]);
	}
	return (!positions.empty());
}
void LowerCase(string & line)
{
	transform(line.begin(), line.end(), line.begin(), ::tolower);
}
void ReadFileToString(ifstream &input, string &inputText, vector<Rows> &rows)
{
	long long endOfLine = 0;
	int numOfLine = 0;
	while (!input.eof())
	{
		string line;
		Rows row;
		getline(input, line, '\n');
		++numOfLine;
		LowerCase(line);
		if (!input.eof())
		{
			line += ' ';
		}
		endOfLine += line.size();
		inputText += line;
		row.numOfRow = numOfLine;
		row.numOfRowEnd = endOfLine;
		rows.push_back(row);
	}
}
Rows findLine(vector<Rows> &rows, unsigned int pos)
{
	Rows row;
	unsigned int endPosOfLastLine = 0;
	for (auto it : rows)
	{
		if (pos < it.numOfRowEnd)
		{
			row.numOfRow = it.numOfRow;
			row.numOfRowEnd = pos;
			row.numOfRowEnd -= endPosOfLastLine;
			return row;
		}
		else
		{
			endPosOfLastLine = it.numOfRowEnd;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "");
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");
	if (!inputFile.is_open())
	{
		outputFile << "Failed to open " << "input.txt" << " for reading\n";
		return 1;
	}
	vector<Rows> rows;
	string inputText, searchText, nameOfFile;
	getline(inputFile, searchText, '\n');
	if (searchText.size() < 1 || searchText.size() > 255)
	{
		outputFile << "Error of search word\n";
	}
	getline(inputFile, nameOfFile, '\n');
	if (nameOfFile.empty())
	{
		outputFile << "Error of name file for searching\n";
		return 1;
	}
	ifstream textFile(nameOfFile);
	ReadFileToString(textFile, inputText, rows);
	LowerCase(searchText);
	if (inputText.size() < searchText.size() || inputText.size() == 0)
	{
		outputFile << "Invalid input\n";
		return 1;
	}
	set<unsigned int> substrPositions;
	if (!RabinKarpSearch(substrPositions, inputText, searchText))
	{
		cout << "Search word not found\n";
		return 1;
	}
	outputFile << "Found position :\n";
	
	for (auto it : substrPositions)
	{
		Rows outputRow;
		outputRow = findLine(rows, it);
		outputFile << outputRow.numOfRow  << ' '<< outputRow.numOfRowEnd << endl;
	}
	return 0;
}