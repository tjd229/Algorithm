//graph, greedy, dijkstra, bs
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define ll long long
using namespace std;
int a[100000], c[100000],vis[100000];
ll d[100000];
vector<pii > edge[100000];
int bs(int s,int e,int bnd) {
	int res = s-1;
	while (s <= e) {
		int m = (s + e) >> 1;
		if (a[m] <= bnd) {
			res = m;
			s = 1 + m;
		}
		else e=m-1;
	}
	return res;
}
void dijkstra(int n,int src=0) {
	for (int i = 1; i < n; ++i) d[i] = -1;
	priority_queue<pii > q; q.push({0,src});
	while (q.size()) {
		int ix = q.top().second; q.pop();
		if (vis[ix]) continue;
		vis[ix] = 1;
		for (auto e : edge[ix]) {
			int w = e.second;
			int nxt = e.first;
			if (d[nxt]<0 || d[nxt]>d[ix] + w) {
				d[nxt] = d[ix] + w;
				q.push({-d[nxt],nxt});
			}
		}
	}
}
int main() {
	int i,n;
	vector<pii > v;
	for (scanf("%d", &n), i = 0; i < n; ++i) {
		scanf("%d%d", a + i, c + i);
		v.push_back({a[i],c[i]});
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	for (i = 0; i < n; ++i) {
		a[i] = v[i].first, c[i] = v[i].second;
		ans += c[i];
	}
	for (i = 0; i < n; ++i) {
		if (i) edge[i].push_back({i-1,0});
		int r = bs(i + 1, n - 1, a[i] + c[i]);
		if(r!=i)
			edge[i].push_back({ r,0 });		
		if (r + 1 < n)
			edge[i].push_back({r+1,a[r+1]-a[i]-c[i]});
		
	}
	dijkstra(n);
	printf("%I64d",ans+d[n-1]);
 
	return 0;
}