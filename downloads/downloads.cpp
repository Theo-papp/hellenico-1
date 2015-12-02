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
	fin = fopen("downloads.in", "r");
	fout = fopen("downloads.out", "w");

	int n;
	fscanf(fin, "%d", &n);

	vector< vector< double > > files(n, vector<double>(2));
	for (int i = 0; i < n; ++i) {
		fscanf(fin, "%lf %lf", &files[i][0], &files[i][1]);
	}

	sort(files.begin(), files.end(), compare);

	int speed = files[0][0];
	double result = files[0][1];
	double timePassed = files[0][1];
	if (n != 1) {
		for (int i = 1; i < n; ++i) {
			speed += files[i][0];
			files[i][1] -= timePassed;
			double newSize = files[i][1] * files[i][0];
			result += (newSize / speed);
			timePassed += (newSize / speed);
		}
	}

	fprintf(fout, "%d\n", (int) (result + 0.5));
	//	fprintf(fout, "%f\n", result);

	fclose(fin);
	fclose(fout);
	return 0;
}

