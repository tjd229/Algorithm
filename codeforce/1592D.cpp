//graph, bs, math
#include <stdio.h>
#include <vector>
#include <numeric>
#include <set>
using namespace std;
vector<int> edge[1001];
int vis[1001][1001];
int ask(vector<int> &v) {
	printf("? %d",v.size());
	for (auto x : v) printf(" %d", x); 
	printf("\n"); fflush(stdout);
	int x; scanf("%d",&x);
	return x;
	
}
void dfs(int x, int from,int stamp, vector<pair<int,int> > &v) {
	for (auto nxt : edge[x]) {
		if (vis[x][nxt] == stamp - 1 ) {
			vis[x][nxt] = vis[nxt][x] = stamp;
			v.push_back({x,nxt});
		}
		if(nxt!=from)
			dfs(nxt,x, stamp, v);
	}
}
int main() {
	int i, n;
	int stamp = 0;
	for (scanf("%d", &n), i = 1; i < n; ++i) {
		int u, v; scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	vector<int> v(n); iota(v.begin(), v.end(), 1);
	int ab = ask(v);
	int rem = n - 1;
	while (rem > 1) {
		vector < pair<int, int> > h;
		set<int> st; v.clear();
		dfs(1,0, ++stamp, h);
		int half = rem >> 1;
		for (i = 0; i < half; ++i) {
			st.insert(h[i].first);
			st.insert(h[i].second);
		}
		for (auto it : st) v.push_back(it);
		if (ab == ask(v)) rem = half;
		else {
			for (i = 0; i < half; ++i) {
				int u = h[i].first, v = h[i].second;
				vis[u][v] = vis[v][u] = -1;
			}
			rem -= half;
		}
	}
	vector < pair<int, int> > ans;
	dfs(1,0, ++stamp, ans);
	printf("! %d %d",ans[0].first,ans[0].second);
 
	
	return 0;
}