//graph
#include <stdio.h>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;
bool vis[101][1 << 14];
int gem[101];
vector<pii > edge[101];
int _pop_count(int x) {
	int cnt = 0;
	for (; x; x -= (x&-x)) ++cnt;
	return cnt;
}
int bfs() {
	int ans = 0;
	queue<pii > q;
	q.push({1,0});
	vis[1][0] = 1;
	while (q.size()) {
		int x = q.front().first;
		int stat = q.front().second;
		int cnt = _pop_count(stat);
		q.pop();
		if (x == 1 && ans < cnt) ans = cnt;
		for (auto p : edge[x]) {
			int nxt = p.first, c = p.second;
			if (vis[nxt][stat] == 0 && cnt<=c) {
				vis[nxt][stat] = 1;
				q.push({nxt,stat});
			}
			if (gem[x]) {
				int nxt_stat = stat | (1 << (gem[x] - 1));				
				if (vis[x][nxt_stat] == 0 ) {
					vis[x][nxt_stat] = 1;
					q.push({ x,nxt_stat });
				}
			}
		}
	}
	return ans;
}
int main() {
	int i, n, m, K;
	for (scanf("%d%d%d", &n, &m, &K), i = 0; i < K; ++i) {
		int isle; scanf("%d",&isle);
		gem[isle] = i+1;
	}
	for (i = 0; i < m; ++i) {
		int a, b, c; scanf("%d%d%d",&a,&b,&c);
		edge[a].push_back({b,c});
		edge[b].push_back({ a,c });
	}printf("%d",bfs());
	

	return 0;
}
