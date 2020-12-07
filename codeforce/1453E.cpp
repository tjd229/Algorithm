//graph, greedy
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> edge[200001];
int k;
int dfs(int x,int from,int depth) {
	vector<int> v;
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		v.push_back(dfs(nxt,x,1+depth));
	}
	if (v.empty()) return depth;
	sort(v.begin(), v.end());
	if (x == 1) {
		if (v.size() > 1) {
			if (k < v[v.size() - 2] - depth + 1) k = v[v.size() - 2] - depth + 1;
		}
		if (k < v.back() - depth) k = v.back() - depth;
		return 0;
	}
	else {
		if (v.size()>1 && k < v.back()-depth + 1) k = v.back() - depth + 1;
		
		return v[0];
	}
}
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) edge[i].clear();
		for (i = 1; i < n; ++i) {
			int u, v; scanf("%d%d",&u,&v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		k = 1;
		dfs(1, 0, 1);
		printf("%d\n",k);
	}

	return 0;
}