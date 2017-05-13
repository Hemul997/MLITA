// FenvikTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <iostream>

const int MAX_N = pow(10, 5);

using namespace std;

int n;

void init(int nn, vector<int> &fenvikTree)
{
	n = nn;
	fenvikTree.assign(n, 0);
}

int sum(int r, vector<int> &fenvikTree)
{
	int result = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		result += fenvikTree[r];
	return result;
}

void add(int i, int delta, vector<int> &fenvikTree)
{
	for (; i < n; i = (i | (i + 1)))
		fenvikTree[i] += delta;
}

int rsq(int l, int r, vector<int> &fenvikTree)
{
	return sum(r, fenvikTree) - sum(l - 1, fenvikTree);
}

void init(vector<int> &a, vector<int> &fenvikTree)
{
	init((int)a.size(), fenvikTree);
	for (unsigned i = 0; i < a.size(); i++)
	{
		add(i, a[i], fenvikTree);
	}
		
}
int main()
{
	ifstream inputFile("input.txt");
	int n;
	inputFile >> n;
	vector<int> fenvikTree;
	vector<int> A;
	for (int i = 0; i < n; ++i)
	{
		int number;
		inputFile >> number;
		A.push_back(number);
	}
	init(A, fenvikTree);
	for (auto it : fenvikTree)
	{
		cout << it << ' ';
	}
	cout << endl;
	int command = 0;
	cout << "Choose the operation\n1 : ADD\n2 : Rsq\n";
	while (cin >> command)
	{
		if (command == 1)
		{
			int i, d;
			cin >> i >> d;
			add(i, d, fenvikTree);
			cout << "Result of operation " << fenvikTree[i] << endl;
		}
		else
		{
			if (command == 2)
			{
				int i, j;
				cin >> i >> j;
				cout << rsq(i, j, fenvikTree) << endl;
			}
			else
			{
				cout << "Command not available\n";
			}
		}
	}
		
	cout << endl;
	return 0;
}

