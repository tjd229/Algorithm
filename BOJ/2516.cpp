//graph

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> ans[2];
vector<int> edge[100001];
int p[100001];
bool inq[100001];
int main() {
	int i;
	int N,M;
	queue<int> q;
	for (scanf("%d", &N), i = 1; i <= N; ++i) {
		for (scanf("%d", &M); M--;) {
			int monkey;
			scanf("%d",&monkey);
			edge[i].push_back(monkey);
		}
	}
	for (i = 1; i <= N; ++i) {
		int same = 0;
		for (auto v : edge[i]) same += p[i] == p[v];
		if (same > 1) {
			q.push(i);
			inq[i] = 1;
		}
	}
	while (q.size()) {
		int ix = q.front();
		q.pop();
		inq[ix] = 0;
		int same = 0;
		for (auto v : edge[ix]) same += p[ix] == p[v];
		if (same > 1) p[ix] ^= 1;
		for (auto u : edge[ix]) {
			if (inq[u]) continue;
			int same = 0;
			for (auto v : edge[u]) same += p[u] == p[v];
			if (same > 1) {
				inq[u] = 1;
				q.push(u);
			}
		}
	}
	for (i = 1; i <= N; ++i) ans[p[i]].push_back(i);
	if (ans[1].empty()) {
		ans[1].push_back(ans[0].back());
		ans[0].pop_back();
	}
	for (i = 0; i < 2; ++i) {
		printf("\n%d ",ans[i].size());
		for (auto ix : ans[i]) printf("%d ",ix);
	}

	return 0;
}
