// Rabin-Carp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string searchString, inputText; // ������� ������

				 // ������� ��� ������� p
	const int p = 31;
	vector<long long> p_pow(max(searchString.length(), inputText.length()));
	p_pow[0] = 1;
	for (size_t i = 1; i<p_pow.size(); ++i)
		p_pow[i] = p_pow[i - 1] * p;

	// ������� ���� �� ���� ��������� ������ T
	vector<long long> h(inputText.length());
	for (size_t i = 0; i<inputText.length(); ++i)
	{
		h[i] = (inputText[i] - 'a' + 1) * p_pow[i];
		if (i)  h[i] += h[i - 1];
	}

	// ������� ��� �� ������ S
	long long h_s = 0;
	for (size_t i = 0; i<searchString.length(); ++i)
		h_s += (searchString[i] - 'a' + 1) * p_pow[i];

	// ���������� ��� ��������� T ����� |S| � ���������� ��
	for (size_t i = 0; i + searchString.length() - 1 < inputText.length(); ++i)
	{
		long long cur_h = h[i + searchString.length() - 1];
		if (i)  cur_h -= h[i - 1];
		// �������� ���� � ����� ������� � ����������
		if (cur_h == h_s * p_pow[i])
			cout << i << ' ';
	}
    return 0;
}

