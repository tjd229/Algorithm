//graph, dp
#include <stdio.h>
#include <vector>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int mod = 1e9 + 7;
ll c[101][101];
vector<int> edge[101];
int vis[101],stk[101];
ll d[101][101];
int dp(vector<int> &v,int k) {
	d[0][1] = v[0];
	for (int i = 1; i < v.size(); ++i) {
		d[i][1] = (v[i]+d[i-1][1])%mod;
		int n = i + 1;
		for (int j = 2; j <= n; ++j) {
			d[i][j] = (d[i - 1][j]+d[i-1][j-1]*v[i])%mod;
		}
	}
	return d[v.size() - 1][k];
}
int bfs(int x,int k,int stamp) {
	int _k = edge[x].size(); vis[x] = stamp;
	vector<pii > q; 
	for (int i = 0; i < _k; ++i) {
		q.push_back({ edge[x][i],i });
		vis[edge[x][i]] = stamp;
		stk[i] = 1;
	}
	int st = 0, ed = q.size();
	ll cnt = 0;
	while (st < ed) {
		vector<int> v;
		for (int i = 0; i < _k; ++i) {
			if (stk[i]>0)
				v.push_back(stk[i]);
			stk[i] = 0;
		}
		if (v.size() < k) break;
		cnt = (cnt + dp(v, k))%mod;
		while (st < ed) {
			int cur = q[st].first, br = q[st].second;
			for (auto nxt : edge[cur]) {
				if (vis[nxt] == stamp) continue;
				vis[nxt] = stamp;
				q.push_back({nxt,br});
				++stk[br];
			}
			++st;
		}
		ed = q.size();
	}
	return cnt;
}
int main() {
	int i, j,t; c[0][0] = 1;
	int stamp = 1;
	for (i = 1; i <= 100; ++i) {
		c[i][0] = 1;
		for (j = 1; j <= i; ++j)
			c[i][j] = (c[i-1][j-1] + c[i-1][j])%mod;
	}
	for (scanf("%d", &t); t--;) {
		int n, k;
		for (scanf("%d%d", &n,&k), i = 1; i <= n; ++i) edge[i].clear();
		for (i = 1; i < n; ++i) {
			int u, v; scanf("%d%d",&u,&v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		if (k == 2)
			printf("%d\n",c[n][2]);
		else {
			ll ans = 0;
			for (i = 1; i <= n; ++i) {
				if (edge[i].size() >= k)
					ans = (bfs(i, k, stamp++) + ans) % mod;
			}
			printf("%d\n",ans);
		}
	}

	return 0;
}
