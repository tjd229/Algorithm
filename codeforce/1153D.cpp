//graph
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> edge[300001];
int op[300001];
int k;
int dfs(int x) {
	if (edge[x].empty()) {
		++k;
		return -1;
	}
	if(op[x]){//mx
		int mx = -1e9;
		for (auto nxt : edge[x]) {
			int cost = dfs(nxt);
			if (mx < cost) mx = cost;
		}
		return mx;
	}
	else {
		int s = 0;
		for (auto nxt : edge[x]) s += dfs(nxt);
		return s;
	}
}
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",op+i);
	for (i = 2; i <= n; ++i) {
		int f; scanf("%d",&f);
		edge[f].push_back(i);
	}
	printf("%d",dfs(1)+k+1);
	return 0;
}
