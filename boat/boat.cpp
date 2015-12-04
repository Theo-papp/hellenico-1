#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	FILE *fin, *fout;
	fin = fopen("boat.in", "r");
	fout = fopen("boat.out", "w");

	int n;
	fscanf(fin, "%d", &n);

	stack< string > q;	

	for (int i = 0; i < n; ++i) {
		int left, entered;
		fscanf(fin, "%d %d", &left, &entered);
		while (left != 0) {
			q.pop();	
			left--;
		}
		for (int j = 0; j < entered; ++j) {
			char cCar[43];
			fscanf(fin, "%s", cCar);
			string car;
			car.assign(cCar, strlen(cCar));
			q.push(car);
		}
	}

	vector< string > leftCars;
	while (!q.empty()) {
		leftCars.push_back(q.top());
		q.pop();
	}

	sort(leftCars.begin(), leftCars.end());
	for (int i = 0; i < leftCars.size(); ++i) {
		fprintf(fout, "%s\n", leftCars[i].c_str());
	}


	fclose(fin);
	fclose(fout);
	return 0;
}

