#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

void reverse(string& a)
{
	int n = a.length();
	for (int i = 0; i < n / 2; ++i) {
		char c = a[i];
		a[i] = a[n - (i + 1)];
		a[n - (i + 1)] = c;
	}
}

int main()
{
	FILE *fin, *fout;
	fin = fopen("lektira.in", "r");
	fout = fopen("lektira.out", "w");

	char cString[51];
	fscanf(fin, "%s", cString);
	int n = strlen(cString);
	string s;
	s.assign(cString, n);

	string min = "";

	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			string a = s.substr(0, i);
			string b = s.substr(i, j - i);
			string c = s.substr(j, n - j);
			reverse(a);
			reverse(b);
			reverse(c);
	
			if (min.compare("") == 0) {
				min = a + b + c;
			}
			else if (min.compare(a + b + c) > 0) {
				min = a + b + c;
			}
		}
	}

	fprintf(fout, "%s\n", min.c_str());

	fclose(fin);
	fclose(fout);
	return 0;
}

