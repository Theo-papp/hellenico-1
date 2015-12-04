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
	return a.first < b.first;
}

int main()
{
	FILE *fin, *fout;
	fin = fopen("crocodiles.in", "r");
	fout = fopen("crocodiles.out", "w");

	int n;
	fscanf(fin, "%d", &n);

	vector< pair<int, bool> > crocodiles;

	for (int i = 0; i < n; i++) {
		int birth, death;
		fscanf(fin, "%d %d", &birth, &death);
		crocodiles.push_back(make_pair(birth, true));
		crocodiles.push_back(make_pair(death, false));
	}

	sort(crocodiles.begin(), crocodiles.end(), compare);
	
	int result = 0;
	int current = 0;
	for (int i = 0; i < 2 * n; ++i) {
		pair<int, bool> p = crocodiles[i];
		if (p.second) {
			current++;
			result = max(current, result);
		}
		else {
			current--;
		}
	} 

	
	fprintf(fout, "%d\n", result);


	fclose(fin);
	fclose(fout);
	return 0;
}

