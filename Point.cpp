// Implementation File: Point.cpp

// 	Wilfredo Molina, 11/30/12.

#include "Point.h"

Point::Point()
{
	x = y = z = 0;
}

Point::Point(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Point Point::operator*(double rhs)
{
	return Point(this->x * rhs, this->y * rhs, this->z * rhs);
}

Point Point::operator+(Point rhs)
{
	return Point(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
}
