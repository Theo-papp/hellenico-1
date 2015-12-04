#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return (a.second / (double) a.first) > (b.second / (double) b.first);
}

int main()
{
	FILE *fin, *fout;
	fin = fopen("stones.in", "r");
	fout = fopen("stones.out", "w");

	int n, z;
	fscanf(fin, "%d %d", &n, &z);
	vector< pair<int, int> > stones(n);
	
	for (int i = 0; i < n; ++i) {
		fscanf(fin, "%d %d", &stones[i].first, &stones[i].second);
	}

	sort(stones.begin(), stones.end(), compare);
	
	double result = 0;
	double remainingVolume = z;
	for (int i = 0; i < n; ++i) {
		if (stones[i].first < remainingVolume) {
			remainingVolume -= stones[i].first;
			result += stones[i].second;
		}
		else {
			double extra = (stones[i].second / (double) stones[i].first) * remainingVolume;
			result += extra; 
			break;
		}
	}

	fprintf(fout, "%.3lf\n", result);

	fclose(fin);
	fclose(fout);
	return 0;
}

