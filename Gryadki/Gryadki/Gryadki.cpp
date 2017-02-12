// Gryadki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <fstream>
#include <iostream>

const int MaxHeight = 20;
const int MaxLength = 20;

typedef char Pole[MaxHeight][MaxLength];

void Metka(Pole pole, int m , int n)
{
	if (pole[m][n] == '#')
	{
		pole[m][n] = '.';
		Metka(pole, m - 1, n);
		Metka(pole, m + 1, n);
		Metka(pole, m, n - 1);
		Metka(pole, m, n + 1);
	}
}

int main()
{
	std::fstream input("input.txt");
	int m;
	int n;
	input >> m;
	input >> n;
	int top = 0;
	Pole pole;
	for (auto i = 0; i < (m + 1); ++i)
	{
		for (auto j = 0; j < (n + 1); ++j)
		{
			pole[i][j] = '.';
		}
	}
	for (auto i = 1; i < m+1; ++i)
	{
		for (auto j = 1; j < n+1; ++j)
		{
			input >> pole[i][j];
		}
	}
	for (auto i = 1; i < m+1; ++i)
	{
		for (auto j = 1; j < n+1; ++j)
		{
			if (pole[i][j] == '#')
			{
				++top;
				Metka(pole, i, j);
			}
		}
	}
	std::cout << top;
    return 0;
}