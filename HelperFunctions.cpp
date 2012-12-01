// Implementation File: HelperFunctions.cpp

// 	Wilfredo Molina, 11/30/12.

#include "HelperFunctions.h"

bool LessThanOrEqualTo(double a, double b)
{
	double diff = a - b;
	return diff <= EPSILON;
}

double alpha(int k, int n, double t, double h)
{
	return (t + (k - 1) * h) / (1 + (n - 1) * h);
}

double prod(int i, int n, double t, double h)
{
	if (i > n)
		return 1;
	double q = 1;
	for (int j = i; j <= n; j++)
		q *= t + j * h;
	return q;
}

int fact(int n)
{
	if (n == 0)
		return 1;
	if (n <= 2)
		return n;
	return n * fact(n - 1);
}

int choo(int n, int k)
{
	return fact(n) / (fact(k) * fact(n - k));
}
