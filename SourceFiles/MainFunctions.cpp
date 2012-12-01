// Implementation File: MainFunctions.cpp

// 	Wilfredo Molina, 11/30/12.

#include "MainFunctions.h"
#include "HelperFunctions.h"

double B(int k, int n, double t, double h)
{
	return choo(n, k) * (prod(0, k - 1, t, h) * prod(0, n - k - 1, 1 - t, h)) / prod(0, n - 1, 1, h);
}

double BR(int k, int n, double t, double h)
{
	if (k < 0 || k > n)
		return 0;
	if (k == 0 && n == 0)
		return 1;
	return (t + (k - 1) * h) / (1 + (n - 1) * h) * BR(k - 1, n - 1, t, h)
			 + (1 - t + (n - k - 1) * h) / (1 + (n - 1) * h) * BR(k, n - 1, t, h);
}

double PR(int k, int r, int n, double t, double h, double *I)
{
	if (r == 0)
		return I[k];
	else
		return (1 - t + (n - r - k) * h) / (1 + (n - r) * h) * PR(k, r - 1, n, t, h, I)
				 + (t + k * h) / (1 + (n - r) * h) * PR(k + 1, r - 1, n, t, h, I);
}

Point f(Point **set, int k, int l, int r, int n, double t, double s, double h) {
	if (r == 0)
		return set[k][l];
	else
		return f(set, k + 1, l + 1, r - 1, n, t, s, h) * alpha(k + 1, n - r + 1, t, h) * alpha(l + 1, n - r + 1, s, h)
		     + f(set, k + 1, l, r - 1, n, t, s, h) * alpha(k + 1, n - r + 1, t, h) * alpha(n - r + 1 - l, n - r + 1, 1 - s, h)
		     + f(set, k, l + 1, r - 1, n, t, s, h) * alpha(n - r + 1 - k, n - r + 1, 1 - t, h) * alpha(l + 1, n - r + 1, s, h)
		     + f(set, k, l, r - 1, n, t, s, h) * alpha(n - r + 1 - k, n - r + 1, 1 - t, h) * alpha(n - r + 1 - l, n - r + 1, 1 - s, h);
}
