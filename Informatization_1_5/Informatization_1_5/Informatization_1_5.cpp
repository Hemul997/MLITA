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
	
	void FindBuildingArea(Point A, Point C)
	{
		BuildingArea = (C.x - A.x)*(C.y - A.y);
	}
	int GetBuildingArea()const
	{
		return BuildingArea;
	}
private:
	Point A;
	Point C;
	int BuildingArea;
};
bool ErrorOfCoordinats(int x1, int y1, int x2, int y2)
{
	return(x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0);
}
bool ReadStream(fstream input, int x1, int y1 , int x2 ,int y2)
{
	input >> x1;
	input >> y1;
	input >> x2;
	input >> y2;
	return (ErrorOfCoordinats(x1, y1, x2, y2));
}
bool ErrorsOfSize(int a, int b)
{
	return(a < 1 || b < 1 || b > 10000);
}
bool ErrorsOfCounts(int m, int n)
{
	return(n < 0 || n > 10 || m > 2 || m < 1);
}
int main()
{
	int x1, y1, x2, y2, n, m, a, b;

	fstream input("input.txt");
	fstream output("output.txt");
    return 0;
}

