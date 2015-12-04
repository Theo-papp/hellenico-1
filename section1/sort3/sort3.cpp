#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	FILE *fin, *fout;
	fin = fopen("sort3.in", "r");
	fout = fopen("sort3.out", "w");

	int n;
	fscanf(fin, "%d", &n);

	int count[3] = {0, 0, 0};
	vector< int > numbers(n);
	for (int i = 0; i < n; ++i) {
		fscanf(fin, "%d", &numbers[i]);
		count[numbers[i] - 1]++;
	}

	int perNumber[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	for (int i = 0; i < count[0]; ++i) {
		perNumber[0][numbers[i] - 1]++;
	}
	
	for (int i = count[0]; i < count[0] + count[1]; ++i) {
		perNumber[1][numbers[i] - 1]++;
	}
	
	for (int i = count[0] + count[1]; i < n; ++i) {
		perNumber[2][numbers[i] - 1]++;
	}

	int result = 0;
	
	result += min(perNumber[0][1], perNumber[1][0]);
	result += min(perNumber[0][2], perNumber[2][0]);

	int doubleMoves = (count[0] - perNumber[0][0]) - result;
	result += 2 * doubleMoves;
	
	result += min(perNumber[1][2], perNumber[2][1]);

	fprintf(fout, "%d\n", result);
	
	fclose(fin);
	fclose(fout);
	return 0;
}

