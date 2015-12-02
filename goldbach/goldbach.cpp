#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	FILE *fin, *fout;
	fin = fopen("goldbach.in", "r");
	fout = fopen("goldbach.out", "w");

	int n;
	fscanf(fin, "%d", &n);

	vector< int > numbers(n + 1);
	for (int i = 1; i <= n; ++i) {
		numbers[i] = i;
	}
	
	// Sieve of Eratosthenes		
	for (int i = 2; i <= n; ++i) {
		if (numbers[i] != -1) {
			for (int j = 2 * i; j <= n; j += i) {
				numbers[j] = -1;
			}
		}
	}

	for (int i = 2; i <= n / 2; ++i) {
		if (numbers[i] != -1 && numbers[n -i] != -1) {
			fprintf(fout, "%d %d\n", numbers[i], numbers[n - i]);
			break;
		}
	}


	fclose(fin);
	fclose(fout);
	return 0;
}

