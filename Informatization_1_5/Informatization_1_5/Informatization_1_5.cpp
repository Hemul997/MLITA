// Informatization_1_5.cpp : Defines the entry point for the console application.
//Mошкин Никита ПС-22.
//1.5. Информатизация садоводства (8)
//Дачный участок Степана Петровича имеет форму прямоугольника размером a x b.На участке
//имеется n построек, причем основание каждой постройки — прямоугольник со сторонами,
//параллельными сторонам участка.
//Вдохновленный успехами соседей, Степан Петрович хочет посадить на своем участке m видов
//плодовых культур(участок Степана Петровича находится в северной местности, поэтому m = 1
//или m = 2).Для каждого вида растений Степан Петрович хочет выделить отдельную
//прямоугольную грядку со сторонами, параллельными сторонам участка.Само собой, грядки не
//могут занимать территорию, занятую постройками или другими грядками.
//Степан Петрович хочет расположить грядки таким образом, чтобы их суммарная площадь была
//максимальной.Грядки не должны пересекаться, но могут касаться друг друга.
//Требуется написать программу, которая по заданным размерам участка и координатам
//построек определяет оптимальное расположение планируемых грядок.

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

struct Point
{
	int x, y;
};
class Building
{
public:
	Building(int x1, int y1, int x2, int y2)
	{
		A.x = x1;
		A.y = y1;
		C.x = x2;
		C.y = y2;
		FindBuildingArea(A, C);
	}
	int GetBuildingArea()const
	{
		return BuildingArea;
	}
private:
	Point A;
	Point C;
	int BuildingArea;
	void FindBuildingArea(Point A, Point C)
	{
		BuildingArea = (C.x - A.x)*(C.y - A.y);
	}
};
bool IsErrorOfCoordinats(int x1, int y1, int x2, int y2, int a, int b);
bool ReadCoordinats(fstream &input, int x1, int y1, int x2, int y2, int a, int b);
void ReadNumbers(fstream &input, int a, int b);
bool IsErrorOfSize(int a, int b);
bool IsErrorOfCounts(int n, int m);

int main()
{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, n = 0, m = 0, a = 0, b = 0;
	vector<Building> gardenBuildings;
	fstream inputFile("input.txt");
	fstream outputFile("output.txt");
	if (!inputFile.is_open())
	{
		cout << "Failed to open input file for reading\n";
		return 1;
	}
	if (!outputFile.is_open())
	{
		cout << "Failed to open output file for writing\n";
		return 1;
	}
	if (inputFile.peek() == ifstream::traits_type::eof())
	{
		cout << "Input file is empty\n";
		return 1;
	}
	else
	{
		ReadNumbers(inputFile, n, m);
	}
	if (IsErrorOfCounts(n, m))
	{
		cout << "Error of counts of buildings or fruit cultures\n";
		return 1;
	}
	ReadNumbers(inputFile, a, b);
	if (IsErrorOfSize(a, b))
	{
		cout << "Error of garden plot\n";
		return 1;
	}
	
	for (auto i = 0; i < n; ++i)
	{
		if (ReadCoordinats(inputFile, x1, y1, x2, y2, a, b))
		{
			Building newBuild(x1, y1, x2, y2);
			gardenBuildings.push_back(newBuild);
		}
		else
		{
			cout << "Error of coordinats\n";
			return 1;
		}
	}

    return 0;
}

bool IsErrorOfCoordinats(int x1, int y1, int x2, int y2, int a, int b)
{
	return(x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 > x2 || x2 > a || y1 > b || y2 > b);
}
bool ReadCoordinats(fstream &input, int x1, int y1, int x2, int y2, int a, int b)
{
	input >> x1;
	input >> y1;
	input >> x2;
	input >> y2;
	return (IsErrorOfCoordinats(x1, y1, x2, y2, a, b));
}
void ReadNumbers(fstream &input, int a, int b)
{
	input >> a;
	input >> b;
}
bool IsErrorOfSize(int a, int b)
{
	return(a < 1 || b < 1 || b > 10000);
}
bool IsErrorOfCounts(int n, int m)
{
	return(n < 0 || n > 10 || m > 2 || m < 1);
}