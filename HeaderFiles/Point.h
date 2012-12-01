// Specification File: Point.h

// This structure defines the points used by the algorithms.

// 	Wilfredo Molina, 11/30/12.

#ifndef POINT_H
#define POINT_H

struct Point {
	double x, y, z;			// Coordinates

	Point();			// Default Constructor
	Point(double, double, double);	// Constructor
	Point operator*(double);	// Operator this * other Overload
	Point operator+(Point);		// Operator this + other Overload
};

#endif // POINT_H
