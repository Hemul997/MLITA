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
vector<int> order;    //������ ��� ���������� ��������������� ������
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
	int countOfDoctors; // ����� ������
	int countOfReferences;
	fstream input("input.txt");
	fstream output("output.txt");
	input >> countOfDoctors;
	for (int i = 1; i <= countOfDoctors; i++)//����, ������� ��� �� �������
	{
		input >> countOfReferences;
		for (int j = 1; j <= countOfReferences; j++) //����, ������� ��� �� ���������
		{
			input >> graph[i][j]; //���������� ������� ��� ������� (� ������ ������ ����)
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
	//for (int i = 0; i<countOfDoctors; i++) //����, ������� ��� �� �������
	//{
	//	for (int j = 0; j<countOfDoctors; j++) //����, ������� ��� �� ���������
	//		cout << graph[i][j] << ' '; //����� ��������� i ������ ������� ����� ������
	//	cout << endl; //������� �� ��������� ������
	//}
    return 0;
}

