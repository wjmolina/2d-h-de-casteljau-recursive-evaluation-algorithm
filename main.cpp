// Client File: main.cpp

// This program creates a 2-D h-Bezier surface. It prompts the user for a perfect-
// square number of points and creates a Maple 15 file ready for compilation.

// 	Wilfredo Molina, 11/30/12.

#include <iostream>
#include <fstream>
#include <cmath>

#include "Point.h"
#include "HelperFunctions.h"
#include "MainFunctions.h"
#include "init.h"	// for data and data_len

using namespace std;

int main()
{
	int n, N, cnt = 0;
	double h;

	Point **set, p;
	ofstream file;

	cout << "********************************" << endl;
	cout << "* 2-D h-Bezier Surface Plotter *" << endl;
	cout << "********************************" << endl << endl;
	cout << "Enter h: ";
	cin >> h;
	cout << "Enter the size of the input: ";
	cin >> n;

	// Create and define a 2-D dynamic array of points.
	N = (int)sqrt((double)n);

	set = new Point*[N];

	for (int i = 0; i < N; i++)
		set[i] = new Point[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cout << "Enter point " << ++cnt << " of " << n << ": ";
			cin >> set[i][j].x >> set[i][j].y >> set[i][j].z;
		}

	file.open("output.mw");

	// Initialize the Maple 15 file.
	for (int i = 0; i < data_len; i++)
		file << data[i];

	// Plot the surface.
	file << "with(plots):</Text-field><Text-field prompt=\"&gt; \" style=\"Maple Input\" layout=\"Normal\">pointplot3d({";
	for (double t = 0; LessThanOrEqualTo(t, 1); t += 0.025)
		for (double s = 0; LessThanOrEqualTo(s, 1); s += 0.025) {
			p = f(set, 0, 0, N - 1, N - 1, t, s, h);
			file << '[' << p.x << ',' << p.y << ',' << p.z << ']';
			if (LessThanOrEqualTo(t + 0.025, 1) || LessThanOrEqualTo(s + 0.025, 1))
				file << ',';
		}
	file << "},axes=boxed,color=black);</Text-field></Group></Worksheet>";
	file.close();
	cout << endl << "The process has finished.";

	// Delete the dynamic array.
	for (int i = 0; i < N; i++)
		delete [] set[i];
	delete [] set;

	cin.get();
	return 0;
}
