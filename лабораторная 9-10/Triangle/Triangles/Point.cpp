#include "pch.h"
#include <iostream>
#include "Point.h"

using namespace std;

void Point::Show() const
{
	cout << " (" << x << "," << y << ")";
}

void Point::operator +=(Point& p)
{
	x += p.x; 
	y += p.y;
}