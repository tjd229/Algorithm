//graph, greedy
#include <stdio.h>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;
vector<int> edge[200001];
int nl[200001];
int rm[200001];
int n, k;
void rm_k(int ix) {
	int cnt = 0;
	for (int i = 0; i < edge[ix].size() && cnt<k; ) {
		int x = edge[ix][i];
		if (edge[x].size() == 1) {
			++cnt; --nl[ix];
			int ed = edge[ix].size() - 1;
			edge[ix][i] ^= edge[ix][ed] ^= edge[ix][i] ^= edge[ix][ed];
			edge[ix].pop_back();
			rm[x] = 1;
		}
		else ++i;
	}
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i;
		for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i) {
			edge[i].clear();
			nl[i] = 0;
			rm[i] = 0;
		}
		for (i = 1; i < n; ++i) {
			int x, y; scanf("%d%d",&x,&y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		priority_queue<pii > q;
		int ans = 0;
		for (i = 1; i <= n; ++i) {
			for (auto x : edge[i])
				nl[i] += edge[x].size() == 1;
			q.push({nl[i],i});
		}
		while (q.size()) {
			int cnt = q.top().first;
			int ix = q.top().second;
			q.pop();
			if (rm[ix]) continue;
			if (nl[ix] != cnt) continue;
			if (cnt < k) break;
			++ans;
			rm_k(ix);
			q.push({nl[ix],ix});
			if (edge[ix].size() == 1) {
				int x = edge[ix][0];
				q.push({++nl[x],x});
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}