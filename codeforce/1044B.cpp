//graph
#include <stdio.h>
#include <vector>
using namespace std;
int tjd[1001];
int LC[1000];
int dfs(int x,int from,int stamp,vector<int> *edge) {
	if (tjd[x] == stamp) return x;
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		int node = dfs(nxt, x, stamp, edge);
		if (node) return node;
	}
	return 0;
}
int main() {
	int i, n, t;
	for (scanf("%d", &t); t--;) {
		vector<int> edge[1001];
		int k1, k2;
		int s;
		for (scanf("%d", &n), i = 1; i < n; ++i) {
			int a, b; scanf("%d%d",&a,&b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		for (scanf("%d", &k1), i = 0; i < k1; ++i) {
			int x; scanf("%d",&x);
			tjd[x] = t + 1;
		}
		for (scanf("%d", &k2), i = 0; i < k2; ++i) {
			int y; scanf("%d", &y);
			LC[y] = t + 1;
			s = y;
		}
		printf("B %d\n", s); fflush(stdout);
		scanf("%d",&s);
		s = dfs(s, 0, t + 1, edge);
		printf("A %d\n", s); fflush(stdout);
		int res; scanf("%d", &res);
		printf("C %d\n", LC[res] == t + 1? s:-1); fflush(stdout);
	}
	return 0;
}