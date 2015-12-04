#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

bool compare(vector<string> a, vector<string> b)
{
	return a[1] < b[1];
}

int main()
{
	FILE *fin, *fout;
	fin = fopen("names.in", "r");
	fout = fopen("names.out", "w");

	int n;
	fscanf(fin, "%d", &n);

	vector< vector< string > > names(n, vector<string>(2));
	for (int i = 0; i < n; ++i) {
		char cString[20];
		fscanf(fin, "%s", cString);
		names[i][0].assign(cString, strlen(cString));
	
		int l = names[i][0].length();
		string doubleName = names[i][0] + names[i][0];
		vector< string > combinations(l);
		for (int i = 0; i < l; ++i) {
			combinations[i] = doubleName.substr(i, l);
		}
		sort(combinations.begin(), combinations.end());
		names[i][1] = combinations[0];
	}

	sort(names.begin(), names.end(), compare);

	fprintf(fout, "%s\n", names[0][0].c_str());

	fclose(fin);
	fclose(fout);
	return 0;
}

