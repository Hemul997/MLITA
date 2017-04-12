// Spravka.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
const int MAX_VERTEX_COUNT = 100;


bool used[MAX_VERTEX_COUNT];
vector<int> order;    //массив для сохранения пронумерованных вершин
vector<vector<int>> graph(MAX_VERTEX_COUNT, vector <int>(MAX_VERTEX_COUNT));

void dfs(int v)
{
	used[v] = true;
	for (size_t i = 0; i <= graph.size(); i++) 
{
		int to = graph[v][i];
		if (!used[to])
		{
			dfs(to);
		}	
	}
	order.push_back(v);
}
int main()
{
	int countOfDoctors; // число вершин
	int countOfReferences;
	fstream input("input.txt");
	fstream output("output.txt");
	input >> countOfDoctors;
	for (int i = 1; i <= countOfDoctors; i++)//цикл, который идёт по строкам
	{
		input >> countOfReferences;
		for (int j = 1; j <= countOfReferences; j++) //цикл, который идёт по элементам
		{
			input >> graph[i][j]; //заполнение вектора или массива (в данном случае ввод)
		}
	}
	for (int i = 1; i <= countOfDoctors; i++)
	{
		used[i] = false;
	}
		
	order.clear();
	for (int i = 1; i <= countOfDoctors; i++)
	{
		if (!used[i])
		{
			dfs(i);
		}
			
	}
	cout << "Doctors:\n";
	for (int u : order)
	{
		cout << u << endl;
	}
	//for (int i = 0; i<countOfDoctors; i++) //цикл, который идёт по строкам
	//{
	//	for (int j = 0; j<countOfDoctors; j++) //цикл, который идёт по элементам
	//		cout << graph[i][j] << ' '; //вывод элементов i строки вектора через пробел
	//	cout << endl; //переход на следующую строку
	//}
    return 0;
}

