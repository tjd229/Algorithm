//graph, dp, greedy
//https://programmers.co.kr/learn/courses/30/lessons/70132
#include <string>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
vector<int> edge[200000];
int d[200000];
int dp[200000][2];//one way, round
void dfs(int x, int from) {
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		d[nxt] = d[x] + 1;
		dfs(nxt, x);		
	}
}
void path(int x, int from, int &ans) {
	vector<pii > v0, v1;
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		path(nxt, x, ans);
		v0.push_back({ dp[nxt][0],nxt });
		v1.push_back({ dp[nxt][1],nxt });
	}
	sort(v0.begin(), v0.end()); sort(v1.begin(), v1.end());
	int sz = v1.size();
	ans = max(ans, 1 + d[x]);
	if (sz) {
		dp[x][0] = v0.back().first;
		dp[x][1] = v1.back().first;
		ans = max(ans, dp[x][0] + d[x] + 1);
		ans = max(ans, dp[x][1] + d[x] + 1);
	}
	if (sz > 1) {
		int d0 = v0.back().second;
		int d1 = v1.back().second;
		
		if (d0 == d1) d0 = v0[sz - 2].second;
		dp[x][1] = max(dp[x][1], dp[d0][0] + dp[d1][1]);
		d1 = v1[sz - 2].second, d0 = v0.back().second;
		if (d0 == d1) d0 = v0[sz- 2].second;
		dp[x][1] = max(dp[x][1], dp[d0][0] + dp[d1][1]);

		ans = max(ans, v1[sz - 1].first + v1[sz - 2].first + 1 + d[x]);
	}
	++dp[x][0]; ++dp[x][1];
}
int solution(vector<vector<int>> t) {
	int answer = 0;
	for (auto p : t) {
		int u = p[0], v = p[1];
		edge[u].push_back(v);
		edge[v].push_back(u);
	} 
	int rt = 0,mx=0;
	int n = t.size() + 1;
	dfs(0, -1);
	for (int i = 0; i < n; ++i) {
		if (mx < d[i]) {
			rt = i;
			mx = d[i];
		}
	}
	d[rt] = 0; mx = 0;
	dfs(rt, -1);
	for (int i = 0; i < n; ++i) {
		if (mx < d[i]) {
			rt = i;
			mx = d[i];
		}
	}
	d[rt] = 0; mx = 0;
	dfs(rt, -1);
	path(rt, -1, answer);
	return answer;
}
