// Segment Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

const int MAXN = 100;
using namespace std;
int tree[4 * MAXN];
int add[4 * MAXN];
//������ ��������. � �������� �������� �����
//���������� ������ �� ������������ �������.
//v - ����� ������� �������; tl, tr - ������� ���������������� �������
void build(int a[], int v, int tl, int tr) 
{
	if (tl == tr)
	{
		tree[v] = a[tl];
	}
	else 
	{
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
}

//������ �����
//l, r - ������� �������;
//v - ����� ������� �������; tl, tr - ������� ���������������� �������
int rsq(int v, int tl, int tr, int l, int r) 
{
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return tree[v];
	int tm = (tl + tr) / 2;
	return rsq(v * 2, tl, tm, l, min(r, tm))
		+ rsq(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void Add(int idx, int val, int v, int tl, int tr) {
	//������� 1
	if (idx <= tl && tr <= idx) {    //�� ��, ��� � idx == tl == tr
		tree[v] += val;
		return;
	}

	//������� 2
	if (tr < idx || idx < tl) {
		return;
	}

	//������� 3
	int tm = (tl + tr) / 2;
	Add(idx, val, v * 2, tl, tm);
	Add(idx, val, v * 2 + 1, tm + 1, tr);
	tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

int main()
{
	//���� �������...
	ifstream inputFile("input.txt");
	int n;
	inputFile >> n;
	int A[MAXN];
	for (int i = 0; i < n; ++i)
	{
		int number;
		inputFile >> number;
		A[i] = number;
	}
	build(A, 1, 0, n - 1);//��������� ����� ������.
	int command;
	cout << "Choose the operation\n1 : ADD\n2 : Rsq\n";
	while (cin >> command)
	{
		if (command == 1)
		{
			int i, d;
			cin >> i >> d;
			Add(i, d, 1, 0, n - 1);
		}
		else
		{
			if (command == 2)
			{
				int i, j;
				cin >> i >> j;
				cout << rsq(1, 0, n - 1, i, j) << endl;
			}
			else
			{
				cout << "Command not available\n";
			}
		}
	}
}
	
								//����� ������ ������� ���� get_sum(l, r, 1, 0, n - 1) � update(idx, val, 1, 0, n - 1);
