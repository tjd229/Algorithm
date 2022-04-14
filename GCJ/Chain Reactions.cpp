//graph, greedy
//https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a45ef7
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
vector<int> edge[100001];
int F[100001],mx[100001];
queue<int> q;
void dfs(int x) {
	int sz = edge[x].size();
	for (auto nxt : edge[x]) {
		dfs(nxt);
	}
	if (sz == 1) mx[x] = max(mx[x], mx[edge[x][0]]);
	else if(sz>1){
		int c = mx[edge[x][0]];
		for (int i = 1; i < sz; ++i) {
			c = min(c, mx[edge[x][i]]);
		}
		mx[x] = max(c, mx[x]);
	}
}
int dfs2(int x) {
	int dir = -1;
	int opt = 2e9;
	int sz = edge[x].size();
	if (sz == 0) return F[x];
	else if (sz == 1) {
		int res = dfs2(edge[x][0]);
		return max(F[x], res);
	}
	else {
		for (int i = 0; i < sz; ++i) {
			int nxt = edge[x][i];
			if (mx[nxt] < opt) {
				opt = mx[nxt];
				dir = i;
			}
		}
		
		for (int i = 0; i < sz; ++i) {
			if (i == dir) continue;
			q.push(edge[x][i]);
		}
		int res = dfs2(edge[x][dir]);
		return max(F[x], res);
	}
}
int main() {
	int T,tc;
	for (scanf("%d", &T), tc = 1; tc <= T; ++tc) {
		int i, N;
		vector<int> rt;
		for (scanf("%d", &N), i = 1; i <= N; ++i) {
			scanf("%d", F + i);
			mx[i] = F[i];
		}
		for (i = 1; i <= N; ++i) {
			int P; scanf("%d",&P);
			if (P == 0) rt.push_back(i);
			else {
				edge[P].push_back(i);
			}
		}
		for (auto x : rt) {
			dfs(x); q.push(x);
		}
		ll ans = 0;
		while (q.size()) {
			int x = q.front(); q.pop();
			ans += dfs2(x);
		}

		

		printf("Case #%d: %lld\n", tc,ans);
		for (i = 1; i <= N; ++i) edge[i].clear();
		
	}

	return 0;
}
	