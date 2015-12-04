#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	FILE *fin, *fout;
	fin = fopen("tickets.in", "r");
	fout = fopen("tickets.out", "w");

	int n;
	fscanf(fin, "%d", &n);

	int discounts[4] = {1, 2, 3, 5};
	int persons[4];
	int discount = 0;
	for (int i = 0; i < 4; ++i) {
		fscanf(fin, "%d", &persons[i]);
		if (n >= persons[i]) {
			discount = discounts[i];
		}
	}

	int result = (10 - discount) * n;
	for (int i = 0; i < 4; ++i) {
		if (persons[i] >= n) {
			result = min(result, (10 - discounts[i]) * persons[i]);
		}
	}

	fprintf(fout, "%d\n", result);

	fclose(fin);
	fclose(fout);
	return 0;
}

