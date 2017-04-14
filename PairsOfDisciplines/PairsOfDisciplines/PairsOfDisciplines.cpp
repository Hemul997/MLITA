// PairsOfDisciplines.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int ARGUMENT_COUNT = 3;

bool cyclic(int v, int &cycle_st, vector<int> *graph, vector <int> &color);
void dfs(int v, vector <int> *graph, vector<bool> &used, vector <int> &answer);
void topological_sort(int n, vector <int> *graph, vector<bool> &used, vector <int> &answer);

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
	inputFile >> countOFDisciplines;
	vector <int> graph[300]; // ����
	vector <bool> used(countOFDisciplines);
	vector<int> answer;
	vector<int> color(countOFDisciplines, 0); //������, �������� ���-�� ��������� ��� ������ �������.
	int cycle_st = -1;
	for (int i = 0; i < countOFDisciplines; i++) {
		inputFile >> firstDiscipline >> secondDiscipline;
		graph[firstDiscipline - 1].push_back(secondDiscipline - 1);
	}
	for (int i = 0; i < countOFDisciplines; i++) {
		if (cyclic(i, cycle_st, graph, color)) //�������� ����� �� ������������
			break;
	}
	if (cycle_st != -1) {
		outputFile << "-1";
	}
	else {
		topological_sort(countOFDisciplines, graph, used, answer);
		for (size_t i = 0; i < answer.size(); i++)
		{
			outputFile << answer[i] << " ";
		}
		outputFile << endl;
	}
    return 0;
}

bool cyclic(int v, int &cycle_st, vector<int> *graph, vector <int> &color) { //�������� ����� �� �����������
	color[v] = 1;
	for (size_t i = 0; i < graph[v].size(); ++i) {
		int to = graph[v][i];
		if (color[to] == 0) { //���� � ������� �� ������� �� ����
			if (cyclic(to, cycle_st, graph, color))  return true;
		}
		else if (color[to] == 1) { //���� � ��������� ������� ����� �������, �� ������, ��� ������ ����
			cycle_st = to; // � ������ �������� ���������� 
			return true;
		}
	}
	color[v] = 2; //���������, ��� � ������� ������ �� ���� ������� �� �����
	return false;
}
void dfs(int v, vector <int> *graph, vector<bool> &used, vector <int> &answer) {
	used[v] = true; //���������, ��� ������������ ������ �������
	for (size_t i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i]; //�� ������ �������� �� ���� ��������, � ������� ����� ������ �� ������� v
		if (!used[to])//� ���� ������� �� �������������, �� ��������� �������� ������ � ������� ��� ��
			dfs(to, graph, used, answer);
	}
	answer.push_back(v + 1); // ������� ������� � ������, �������� ���������
}

void topological_sort(int n, vector <int> *graph, vector<bool> &used, vector <int> &answer) {
	for (int i = 0; i < n; i++) //���������, ��� �� ���� ������� �� ���� ������������
		used[i] = false;
	for (int i = 0; i < n; i++)
		if (!used[i]) //���� � ���� ���������� �������� ������� �� ��������������
			dfs(i, graph, used, answer); // �� �������� ��� �� �������� ������ � �������
	reverse(answer.begin(), answer.end());
}