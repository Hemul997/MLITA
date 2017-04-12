// Perestanovki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <iostream>

const int MAX = 256;
using namespace std;

void swap(int *a, int i, int j) 
{
	int s = a[i]; a[i] = a[j]; a[j] = s;
}
bool NextSet(int *a, int n) {
	int j = n - 2;
	while (j != -1 && a[j] >= a[j + 1]) j--;
	if (j == -1)
	{
		return false; // больше перестановок нет
	}
	int k = n - 1;
	while (a[j] >= a[k]) k--;
	swap(a, j, k);
	int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
	while (l < r)
	{
		swap(a, l++, r--);
	}
	return true;
}
void Print(int *a, int n)// вывод перестановки 
{ 
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}	
	cout << endl;
}
int main()
{
	fstream input("input.txt");
	int n, k;
	input >> n >> k;
	int a[MAX];
	for (auto i = 0; i < n; i++)
	{
		input >> a[i];
	}
	for (auto i = 0; i < k; i++)
	{
		NextSet(a, n);
		Print(a, n);
	}
    return 0;
}

