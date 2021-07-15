//graph, greedy
#include <stdio.h>
#include <vector>
#define pii pair<int,int>
using namespace std;
vector<int> edge[200001];
vector<pii > ad, rm;
int vis[200001];
int cut[200001];
int a[200001], b[200001];
inline int to(int src, int u, int v) {
	return src == u ? v : u;
}
void dfs(int x,int from) {
	int num_c = 0;
	for (auto ix : edge[x]) {
		int nxt = to(x, a[ix], b[ix]);
		if (nxt == from) continue;
		dfs(nxt, x);
		if (cut[nxt]) {
			rm.push_back({a[ix],b[ix]});
			a[ix] = b[ix] = 0;
		}
		else ++num_c;		
	}
	cut[x] = num_c > 1;
	for (auto ix : edge[x]) {
		if (num_c <= 2) break;
		if (a[ix] + b[ix] == 0) continue;
		int nxt = to(x, a[ix], b[ix]);
		if (nxt == from) continue;
		rm.push_back({a[ix],b[ix]});
		a[ix] = b[ix] = 0;
		--num_c;
	}
}
int path(int x, int stamp) {
	vis[x] = stamp;
	for (auto ix : edge[x]) {
		if (a[ix] + b[ix] == 0) continue;
		int nxt = to(x, a[ix], b[ix]);
		if (vis[nxt] == stamp) continue;
		return path(nxt, stamp);
	}
	return x;
}
int main() {
	int t;
	int stamp = 1;
	for (scanf("%d", &t); t--;) {
		int i, n; 
		rm.clear(); ad.clear();
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			edge[i].clear();
			cut[i] = 0;
		}
		for (i = 1; i < n; ++i) {
			scanf("%d%d",&a[i],&b[i]);
			edge[a[i]].push_back(i);
			edge[b[i]].push_back(i);
		}
		dfs(1, 0);
		vector<pii > snake;
		for (i = 1; i <= n; ++i) {
			if (vis[i] < stamp) {
				int head = path(i, stamp);
				int tail = path(head, stamp + 1);
				snake.push_back({head,tail});
			}
		}
		for (i = 1; i < snake.size(); ++i) {
			int x = snake[i - 1].second;
			int y = snake[i].first;
			ad.push_back({x,y});
		}
		int k = ad.size();
		for (printf("%d\n",k),i = 0; i < k; ++i)
			printf("%d %d %d %d\n",rm[i].first,rm[i].second,ad[i].first,ad[i].second);
		stamp += 2;
	}

	return 0;
}