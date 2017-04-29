// Rabin-Carp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp> 
#include <algorithm>
#include <cctype>

using namespace std;


const int NUMERATOR = 52;
const unsigned long long DENOMENATOR = pow(2, 1e56);

unsigned long long findAcceleratingCoeff(long long & m)
{
	unsigned long long h = 1;

	for (long long i = 1; i < m; ++i)
	{
		h *= NUMERATOR % DENOMENATOR;
	}
	return h;

}
bool compareStrings(const string & inputText, const string & searchString, long long & pos) {

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
bool RabinKarpSearch(vector<long long> &positions, const string & inputText, const string & searchString) 
{
	long long inputTextSize = inputText.size(), searchStringSize = searchString.size(), searchStringHash = 0, textBoxHash = 0;

	if (inputTextSize < searchStringSize || inputTextSize == 0 || searchStringSize == 0)
	{
		return false;
	}

	unsigned long long acceleratingCoeff(findAcceleratingCoeff(searchStringSize));

	for (long long i = 0; i < searchStringSize; ++i) 
	{
		searchStringHash = countHash(searchStringHash, searchString[i]);
		textBoxHash = countHash(textBoxHash, inputText[i]);
	}

	for (long long pos = 0; pos <= inputTextSize - searchStringSize; ++pos) 
	{
		if (searchStringHash == textBoxHash && compareStrings(inputText, searchString, pos))
		{
			positions.push_back(pos + 1);
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
void ReadFileToString(fstream &input, string &inputText)
{
	while (!input.eof())
	{
		string line;
		getline(input, line, '\n');
		inputText += line;
	}
}
int main()
{
	fstream inputFile("input.txt");

	string inputText, searchText = "pol Lop";
	LowerCase(searchText);
	inputText = "";
	ReadFileToString(inputFile, inputText);
	cout << inputText << endl;
	vector<long long> substrPositions;
	cout << "input word = " << inputText << " --- substring = " << searchText << endl;
	if (!RabinKarpSearch(substrPositions, inputText, searchText))
	{
		cout << "Search word not found\n";
		return 0;
	}
	cout << "Found position : ";
	for (auto it : substrPositions)
	{
		cout << it << " ";
	}
	cout << endl;
}