//graph, math
#include <stdio.h>
#include <vector>
#define pii pair<int,int>
using namespace std;
int cum[200001];
int vis[200001];
vector<pii > edge[200001], elves[200001];
int _pop_count(int x) {
	int pop = 0;
	while (x) {
		++pop;
		x -= x & -x;
	}
	return pop;
}
bool dfs(int x,int parity) {
	vis[x] = 1; cum[x] = parity;
	for (auto p : edge[x]) {
		int nxt = p.first, w = p.second;
		if (w != -1) {
			if (vis[nxt]) {
				if (cum[nxt] != parity ^ (_pop_count(w) & 1))
					return false;
			}
			else if (!dfs(nxt, parity ^ (_pop_count(w) & 1)))
				return false;
		}
	}
	for (auto p : elves[x]) {
		int nxt = p.first, w = p.second;
		if (vis[nxt]) {
			if (cum[nxt] != parity ^ w)
				return false;
		}
		else if (!dfs(nxt, parity ^ w))
			return false;
	}
	return true;
}
void print(int x,int from) {
	for (auto p : edge[x]) {
		int nxt = p.first, w = p.second;
		if (nxt == from) continue;
		if (w == -1)
			printf("%d %d %d\n",x,nxt,cum[x]^cum[nxt]);
		else
			printf("%d %d %d\n", x, nxt, w);
		print(nxt, x);
	}
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n, m;
		for (scanf("%d%d", &n, &m), i = 1; i < n; ++i) {
			int x, y, v; scanf("%d%d%d",&x,&y,&v);
			edge[x].push_back({ y,v });
			edge[y].push_back({ x,v });
 
		}
		for (i = 1; i <= m; ++i) {
			int a, b, p; scanf("%d%d%d",&a,&b,&p);
			elves[a].push_back({ b,p });
			elves[b].push_back({ a,p });
		}
		bool flag = 1;
		for (i = 1; flag && i <= n; ++i) {
			if (vis[i] == 0)
				flag &= dfs(i, 0);
		}
		if (flag) {
			printf("YES\n"); print(1, 0);
		}
		else printf("NO\n");
		for (i = 1; i <= n; ++i) {
			vis[i] = cum[i] = 0;
			edge[i].clear(); elves[i].clear();
		}
	}
 
	return 0;
}