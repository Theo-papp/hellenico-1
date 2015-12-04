#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int getIndex(char c) {
	if (c == 'A') {
		return 0;
	}
	else if (c == 'G') {
		return 1;
	}
	else if (c == 'C') {
		return 2;
	}
	else {
		return 3;
	}
}

int getMax(int numbers[4]) 
{
	return max(numbers[0], max(numbers[1], max(numbers[2], numbers[3])));
}

int main()
{
	FILE *fin, *fout;
	fin = fopen("dna.in", "r");
	fout = fopen("dna.out", "w");

	int n, k;
	fscanf(fin, "%d %d", &n, &k);
		
	char cString[n + 1];
	fscanf(fin, "%s", cString);

	int changes = n;
	for (int i = k; i >= 1; --i) {
		int tmpChanges = 0;
		for (int l = 0; l < i; ++l) {
			int numbers[4] = {0, 0, 0, 0};
			int elements = 0;
			for (int j = l; j < n; j += i) {
				numbers[getIndex(cString[j])]++;
				elements++;
			}
			int m = getMax(numbers);
			tmpChanges += (elements - m);
		}
		changes = min(changes, tmpChanges);
	}

	fprintf(fout, "%d\n", changes);

	fclose(fin);
	fclose(fout);
	return 0;
}

