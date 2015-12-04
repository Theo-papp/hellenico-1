#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include "hiddenlib.h"

using namespace std;

/*int treasure = 13;
int N = 1000000;

int getN() {
	cout << "getN()\n";
	return N;
}

void ishidden(int a) {
	cout << "ishidden(" << a << ")\n";
	if (a == treasure) {
		cout << "SOLVED\n";
	}
}

int compare(int a, int b) {
	cout << "compare(" << a << ", " << b << ")\n";
	int distanceA = abs(a - treasure);
	int distanceB = abs(b - treasure);
	if (distanceA < distanceB) {
		return 1;
	}
	else if (distanceA > distanceB) {
		return -1;
	}
	return 0;
}
*/

void solve(int start, int end)
{
	if (start > end) {
		return;
	}
	//cout << "T: " << treasure << endl;

	int middle = (end - start) / 2;
	int a = compare(start, end);
	if (a == 0) {
		ishidden(start + middle);
	}
	else if (a == 1) {
		solve(start, start + middle);
	}
	else {
		solve(start + middle + 1, end);
	}
}

int main()
{
	int n = getN();

	solve(1, n);

	return 0;
}

