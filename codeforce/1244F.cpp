//djs

#include <stdio.h>
#include <vector>
using namespace std;
char chips[200001];
int p[200001];
int sz[200001];
bool stable[200001];
int find(int a) {
	if (p[a] != a)p[a] = find(p[a]);
	return p[a];
}
void un(int a, int b) {
	a = find(a); b = find(b);
	if (a == b)return;
	p[b] = a;
	sz[a] += sz[b];
}
int main() {
	int i, n, k;
	vector<int> q;
	for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i) {
		scanf(" %c",chips+i);
		p[i] = i; sz[i] = 1;
		if (chips[i] == chips[i - 1]) un(i - 1, i);
	}
	if (chips[n] == chips[1]) un(1, n);
	for (i = 2; i < n; ++i) {
		if (chips[i - 1] != chips[i] && chips[i + 1] != chips[i])
			continue;
		stable[i] = 1;
		q.push_back(i);
	}
	if (chips[n] == chips[1] || chips[2] == chips[1]) {
		stable[1] = 1;
		q.push_back(1);
	}
	if (chips[n] == chips[1] || chips[n] == chips[n - 1]) {
		stable[n] = 1;
		q.push_back(n);
	}
	//printf("%d\n",q.size());
	int _k = k;
	for (int fr = 0; fr < q.size() && k;) {//BFS
		--k;
		int end = q.size();
		for (; fr < end; ++fr) {
			int u = q[fr];
			int r = u + 1;
			if (r > n) r = 1;
			int l = u - 1;
			if (l == 0) l = n;
			if (!stable[r]) {
				stable[r] = 1;
				q.push_back(r);
				p[r] = find(u);
			}
			if (!stable[l]) {
				stable[l] = 1;
				q.push_back(l);
				p[l] = find(u);
			}
		}
	}
	for (i = 1; i <= n; ++i) {
		if (stable[i]) {
			int p = find(i);
			chips[i] = chips[p];
		}
		else if(_k&1)
			chips[i] = chips[i] == 'B' ? 'W' : 'B';
	}
	for (i = 1; i <= n; ++i) printf("%c",chips[i]);
	return 0;
}