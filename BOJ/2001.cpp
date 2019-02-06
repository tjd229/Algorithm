//graph
#include <vector>
#include <queue>
#include <stdio.h>
#define pii pair<int,int>
using namespace std;
int gem[101];
vector<pii > edge[101];
int vis[101][1 << 14];
int bit_cnt(int n) {
	int cnt = 0;
	for (; n; n -= (n&-n))++cnt;
	return cnt;
}
int bfs() {
	int ans = 0;
	vis[1][0] = 1;
	queue<pii > q;
	q.push({1,0});

	while (q.size()) {
		int cur = q.front().first;
		int stat = q.front().second;
		int n = bit_cnt(stat);
		q.pop();
		if (cur == 1 && ans < n) ans = n;
		for (auto p : edge[cur]) {
			if (p.second < n) continue;
			int nxt = p.first;
			if (vis[nxt][stat] == 0) {
				vis[nxt][stat] = 1;
				q.push({nxt,stat});
			}
			if (gem[nxt]) {
				int nstat = stat | (1 << (gem[nxt]-1));
				if (p.second < n + 1) continue;
				if (vis[nxt][nstat] == 0) {
					vis[nxt][nstat] = 1;
					q.push({nxt,nstat});
				}
			}
			
		}
	}
	return ans+(gem[1]>0);
}
int main() {
	int i;
	int n, m, K;
	int a, b, c;
	for (scanf("%d%d%d", &n, &m, &K),i=1;i<=K;++i) {
		scanf("%d",&a);
		gem[a] = i;
	}
	while (m--) {
		scanf("%d%d%d",&a,&b,&c);
		edge[a].push_back({b,c});
		edge[b].push_back({ a,c });
	}
	printf("%d",bfs());
	return 0;
}
