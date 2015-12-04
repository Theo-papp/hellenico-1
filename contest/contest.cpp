#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
#include <map>

using namespace std;

struct node {
	vector< pair<struct node *, int> > children;
	int id;
};

int solve(int sum, struct node* root)
{
	int m = sum;
	for (int i = 0; i < root->children.size(); ++i) {
		int res = solve(sum + root->children[i].second, root->children[i].first);
		m = max(m, res);
	} 
	return m;
}

int main()
{
	FILE *fin, *fout;
	fin = fopen("contest.in", "r");
	fout = fopen("contest.out", "w");

	int n;
	fscanf(fin, "%d", &n);
	
	map<int, struct node *> m;

	for (int i = 0; i < n; ++i) {
		struct node* nod = new struct node;
		nod->id = i + 1;
		m[i + 1] = nod;
	}
	
	for (int i = 0; i < n - 1; ++i) {
		int a, b, shells;
		fscanf(fin, "%d %d %d", &a, &b, &shells);
		pair<struct node*, int> p = make_pair(m[b], shells); 
		m[a]->children.push_back(p);
	}

	fprintf(fout, "%d\n", solve(0, m[1]));

	fclose(fin);
	fclose(fout);
	return 0;
}

