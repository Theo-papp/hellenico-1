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

	double discounts[4] = {0.1, 0.2, 0.3, 0.5};
	int persons[4];
	double discount = 0.0;
	for (int i = 0; i < 4; ++i) {
		fscanf(fin, "%d", &persons[i]);
		if (n >= persons[i]) {
			discount = discounts[i];
		}
	}

	int result = (1 - discount) * 10 * n;
	for (int i = 0; i < 4; ++i) {
		if (persons[i] >= n) {
			result = min(result, (int) ((1 - discounts[i]) * 10 * persons[i]));
		}
	}


	fprintf(fout, "%d\n", result);

	fclose(fin);
	fclose(fout);
	return 0;
}

