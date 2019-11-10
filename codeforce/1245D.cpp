//graph, dijkstra

#include <stdio.h>
#include <queue>
#include <vector>
#define ll long long
#define pli pair<ll,int>
#define pii pair<int,int>
using namespace std;
const int mask = 2047;
int x[2001], y[2001];
int c[2001], k[2001];
bool on[2001];
int main() {
	int i, n;
	ll tot = 0;
	vector<pii > con;
	vector<int> bd;
	priority_queue<pli > q;//<w,(u,v)>
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d%d",x+i,y+i);
	for (i = 1; i <= n; ++i) scanf("%d",c+i);
	for (i = 1; i <= n; ++i) scanf("%d",k+i);
	for (i = 1; i <= n; ++i) q.push({-c[i],i});
	on[0] = 1;
 
	while (con.size()<n) {
		
		ll w = -q.top().first;
		int u = q.top().second;
		int v = u & mask; u >>= 11;
		q.pop();
		if (on[v]) continue;
		on[v] = 1;
		con.push_back({ u,v });
		tot += w;
		for (i = 1; i <= n; ++i) {
			if (i == v) continue;
			if (on[i]) continue;
			ll dx = x[i] - x[v];
			ll dy = y[i] - y[v];
			if (dx < 0) dx = -dx;
			if (dy < 0) dy = -dy;
			q.push({-(dy+dx)*(k[i]+k[v]), (v<<11)+i });
		}
	}
	for (auto p : con) {
		if (p.first == 0) bd.push_back(p.second);
	}
	printf("%I64d\n%d\n",tot,bd.size());
	for (auto x : bd) printf("%d ",x);
	for (printf("\n%d\n", n - bd.size()), i = 0; i < n; ++i) {
		if (con[i].first == 0) continue;
		printf("%d %d\n",con[i].first,con[i].second);
	}
	return 0;
}