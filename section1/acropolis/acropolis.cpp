#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(vector<double> a, vector<double> b)
{
	return a[1] < b[1];
}

int main()
{
	FILE *fin, *fout;
	fin = fopen("acropolis.in", "r");
	fout = fopen("acropolis.out", "w");

	int n;
	fscanf(fin, "%d", &n);

	vector< int > numbers(n), numbersWithoutOnes;
	for (int i = 0; i < n; ++i) {
		fscanf(fin, "%d", &numbers[i]);
		if (numbers[i] != 1) {
			numbersWithoutOnes.push_back(numbers[i]);
		}
	}

	sort(numbersWithoutOnes.begin(), numbersWithoutOnes.end());
	int usedNumbers = 0;
	for (int i = 0; i < n; ++i) {
		if (numbers[i] != 1) {
			numbers[i] = numbersWithoutOnes[usedNumbers];
			usedNumbers++;
		}
		fprintf(fout, "%d\n", numbers[i]);
	}


	fclose(fin);
	fclose(fout);
	return 0;
}

