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

	reverse(s);
	string min = s.substr(0, 1);
	int length = 1;

	for (int i = 2; i < n - 2; ++i) {
		string a = s.substr(0, i);
		if (min.compare(a) > 0) {
			min = a;
			length = i;
		}
	}
	fprintf(fout, "%s", min.c_str());
	
	
	min = s.substr(length, 1);
	int length2 = 1; 
	for (int i = 2; i < n - length; ++i) {
		string a = s.substr(length, i);
		if (min.compare(a) > 0) {
			min = a;
			length2 = i;
		}
	}
	fprintf(fout, "%s", b.c_str()); 	
	
	fprintf(fout, "%s", s.substr(length + length2, n - (length + length2).c_str()));

	fclose(fin);
	fclose(fout);
	return 0;
}

