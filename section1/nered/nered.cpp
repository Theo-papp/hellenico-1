#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

int numberOfZeroes(int x, int y, int height, int width, vector< vector< int > >& zeroes, vector< vector< int > > &grid)
{
	int s1, s2;
	s1 = s2 = 0;
	if (y > 0) {
		s1 = zeroes[x + height][y - 1];
	}

	if (x > 0) {
		s2 = zeroes[x - 1][y + width];
	}

	int a = 0;
	if (x > 0 && y > 0) {
		a = zeroes[x - 1][y - 1];
	}

	return zeroes[x + height][y + width] - (s1 + s2) + a;
}

int main()
{
	FILE *fin, *fout;
	fin = fopen("nered.in", "r");
	fout = fopen("nered.out", "w");

	int n, m;
	fscanf(fin, "%d %d", &n, &m);

	vector< vector< int > > grid(n, vector< int > (n));

	for (int i = 0; i < m; i++) {
		int a, b;
		fscanf(fin, "%d %d", &a, &b);
		grid[a - 1][b - 1]++;
	}


	vector< vector< int > > zeroes(n, vector< int > (n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int toAdd = 0;
			if (grid[i][j] == 0) {
				toAdd = 1;
			}
			if (i > 0) {
				if (j > 0) {
					zeroes[i][j] = toAdd + zeroes[i - 1][j] + zeroes[i][j - 1] - zeroes[i - 1][j - 1];
				}
				else {
					zeroes[i][j] = toAdd + zeroes[i - 1][j];
				}
			}
			else {
				if (j > 0) {
					zeroes[i][j] = toAdd + zeroes[i][j - 1];
				}
				else {
					zeroes[i][j] = toAdd;
				}
			}
		}
	}

	int result = INT_MAX;
	for (int i = 1; i <= m; ++i) {
		if (m % i == 0) {
			int height = m / i;
			int width = i;

			if (width > n || height > n) {
				continue;
			}
			
			for (int a = 0; a < n; ++a) {
				if (a + height > n) {
					continue;
				}
				for (int b = 0; b < n; ++b) {
					if (b + width > n) {
						continue;
					}
					else {
						result = min(numberOfZeroes(a, b, height - 1, width - 1, zeroes, grid), result); 
					}
				}
			}
		}
	}

	fprintf(fout, "%d\n", result);


	fclose(fin);
	fclose(fout);
	return 0;
}

