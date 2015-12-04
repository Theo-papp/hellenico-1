#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	FILE *fin, *fout;
	fin = fopen("cubes.in", "r");
	fout = fopen("cubes.out", "w");

	int n, k;
	fscanf(fin, "%d %d", &n, &k);

	int maxHeight = 0;
	if (k >= n) {
		maxHeight = n;
	}
	else {
		maxHeight = k;
		int result = k;
		for (int i = 2; ; ++i) {
			for (int j = 0; j < k; ++j) {
				if (result + i <= n) {
					result += i;
					maxHeight++;
				}
				else {
					goto end;
				}
			}
		}
	}

	end:
	fprintf(fout, "%d\n", maxHeight);

	fclose(fin);
	fclose(fout);
	return 0;
}

