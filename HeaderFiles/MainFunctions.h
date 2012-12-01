// Specification File: MainFunctions.h

// This file contains the main functions used by the program to compute surfaces.

// 	Wilfredo Molina, 11/30/12.

#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H

#include "Point.h"

double B(int, int, double, double);										// Non-Recursive h-Bernstein Polynomial
double BR(int, int, double, double);									// Recursive h-Bernstein Polynomial
double PR(int, int, int, double, double, double*);					// 1-D h-de Casteljau Recursive Evaluation Algorithm
Point f(Point**, int, int, int, int, double, double, double);	// 2-D h-de Casteljau Recursive Evaluation Algorithm

#endif // MAINFUNCTIONS_H
