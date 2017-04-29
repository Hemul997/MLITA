// GameInWords.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool findSubword(const string & word, const string &subWord)
{
	string wordCopy(word);
	for (size_t it = 0; it < subWord.size(); ++it)
	{
		size_t letterPosition = wordCopy.find(subWord[it]);
		if (letterPosition == string::npos)
		{
			return false;
		}
		wordCopy.erase(letterPosition, 1);
	}
	return true;
}
struct {
	bool operator()(string &a, string &b)
	{
		if (a.size() == b.size())
		{
			return b > a;
		}
		else
		{
			return(a.size() > b.size());
		}
	}
} customLess;
int main()
{
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");
	string word, mainWord;
	int score = 0;
	vector<string> subWords;
	vector<string> foundWords;
	inputFile >> mainWord;
	while (!inputFile.eof())
	{
		inputFile >> word;
		if (!inputFile.eof())
		{
			subWords.push_back(word);
		}
	}
	for (auto it = subWords.begin(); it != subWords.end(); it++)
	{
		if (findSubword(mainWord, *it))
		{
			foundWords.push_back(*it);
			score += (*it).size();
		}
	}
	sort(foundWords.begin(), foundWords.end(), customLess);
	outputFile << "Scores: " << score << endl;
	for (auto it: foundWords)
	{
		outputFile << it << endl;
	}
    return 0;
}

