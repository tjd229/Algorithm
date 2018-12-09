//graph, djs

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> comp;
int decomp[2000001];
int a[2000001], b[2000001], p[2000001];
int sz[2000001],cap[2000001];
int test[2000001][3];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void join(int a,int b) {
	a = find(a);
	b = find(b);
	++sz[b];
	if (a == b) return;
	sz[b] += sz[a];
	cap[b] += cap[a];
	p[a] = b;
	//0,1,2, descending
	for (int i = 0; i < 2; ++i) {
		int j = 2;
		int x = test[a][i];
		if (test[b][0] == x || test[b][1]==x) continue;
		test[b][j] = x;
		while (j--) {
			if (test[b][j] > test[b][j + 1]) break;
			test[b][j] ^= test[b][j + 1] ^= test[b][j] ^= test[b][j + 1];
		}
	}
}
int main() {
	int i;
	int n;
	for (scanf("%d", &n), i = 0; i < n; ++i) {
		scanf("%d%d",a+i,b+i);
		comp.push_back(a[i]);
		comp.push_back(b[i]);
	}
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
	for (i = 0; i < n; ++i) {
		int na = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
		decomp[na] = a[i];
		a[i] = na;
		int nb = lower_bound(comp.begin(), comp.end(), b[i]) - comp.begin();
		decomp[nb] = b[i];
		b[i] = nb;
		cap[na] = cap[nb] = 1;
		test[na][0] = p[na] = na;
		test[nb][0] = p[nb] = nb;

	}
	for (i = 0; i < n; ++i) join(a[i], b[i]);
	int ans = 0;
	for (i = 0; i < comp.size() && ans >= 0; ++i) {
		if (p[i] == i) {
			int ix = cap[i] - sz[i];
			if (ix < 0) ans = -1;
			else {
				int day= decomp[test[i][ix]];
				if (ans < day) ans = day;
			}
		}
	}
	printf("%d",ans);

	return 0;
}
