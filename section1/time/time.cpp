#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	FILE *fin, *fout;
	fin = fopen("time.in", "r");
	fout = fopen("time.out", "w");

	int hours, minutes, seconds;
	fscanf(fin, "%d:%d:%d", &hours, &minutes, &seconds);

	seconds = (2 * seconds);
	minutes = (2 * minutes + seconds / 60);
	hours = (2 * hours + minutes / 60);

	fprintf(fout, "%02d:%02d:%02d\n", hours, minutes % 60, seconds % 60);

	fclose(fin);
	fclose(fout);
	return 0;
}

