#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	FILE *fin, *fout;
	fin = fopen("elevator.in", "r");
	fout = fopen("elevator.out", "w");

	int n;
	fscanf(fin, "%d", &n);

	vector< int > numbers(n);
	for (int i = 0; i < n; ++i) {
		fscanf(fin, "%d", &numbers[i]);
	}

	sort(numbers.begin(), numbers.end());

	if (n % 2 == 0) {
		int result = numbers[0] + numbers[n - 1];
		for (int i = 1; i < n / 2; ++i) {
			result = max(result, numbers[i] + numbers[n - (i + 1)]); 
		}
		fprintf(fout, "%d %d\n", n / 2, result);
	}
	else {
		int result = numbers[n - 1];
		for (int i = 0; i < n / 2; ++i) {
			result = max(result, numbers[i] + numbers[n - (i + 2)]); 
		}
		fprintf(fout, "%d %d\n", n / 2 + 1, result);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}

