#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

void qubits(int n, int from, int to, int through, FILE* fout)
{
	if (n <= 1) {
		fprintf(fout, "%c %c\n", from, to);
		return;
	}

	qubits(n - 1, from, through, to, fout);
	qubits(1, from, to, through, fout);
	qubits(n - 1, through, to, from, fout);
}

int main()
{
	FILE *fin, *fout;
	fin = fopen("qubits.in", "r");
	fout = fopen("qubits.out", "w");

	int n;
	fscanf(fin, "%d", &n);
	
	qubits(n, 65, 67, 66, fout);
	
	fclose(fin);
	fclose(fout);
	return 0;
}

