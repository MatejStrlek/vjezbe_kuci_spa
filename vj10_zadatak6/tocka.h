#pragma once
#include <cmath>
struct tocka 
{
	int x;
	int y;
	tocka(int x, int y) 
	{
		this->x = x;
		this->y = y;
	}
	double distance() 
	{
		return sqrt(pow(x,2) + pow(y, 2));
	}
};