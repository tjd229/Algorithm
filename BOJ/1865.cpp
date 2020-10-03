//graph, SPFA


#include <vector>
#include <stdio.h>
#include <queue>
#define pii pair<int,int>
using namespace std;
const int inf = 2e9;
int mat[501][501];
int upd[501];
int d[501];
bool in[501];
bool vis[501];
vector<pii > edge[501];
void dfs(int x,int from) {
	if (vis[x]) return;
	vis[x] = 1;
	for (auto p : edge[x]) {
		int nxt = p.first;
		if (nxt == from) continue;
		dfs(nxt, x);
	}
}
int main() {
	int TC;
	for (scanf("%d", &TC); TC--;) {
		int i, N, M, W;
		for (scanf("%d%d%d", &N, &M, &W), i = 1; i <= N; ++i) {
			upd[i] = 0;
			in[i] = 0;
			vis[i] = 0;
			d[i] = inf;
			edge[i].clear();
			for (int j = 1; j <= N; ++j) mat[i][j] = mat[j][i] = inf;
		}
		for (i = 0; i < M; ++i) {
			int S, E, T; scanf("%d%d%d",&S,&E,&T);
			if (mat[S][E] > T)
				mat[S][E] = mat[E][S] = T;
		}
		for (i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (mat[i][j] < inf) edge[i].push_back({ j,mat[i][j] });
			}
		}
		//dfs
		vector<int> src;
		for (i = 1; i <= N; ++i) {
			if (vis[i] == 0) {
				dfs(i,0);
				src.push_back(i);
			}
		}
		for (i = 0; i < W; ++i) {
			int S, E, T; scanf("%d%d%d", &S, &E, &T);
			edge[S].push_back({E,-T});
		}
		queue<int> q;
		for (auto x : src) {
			q.push(x);
			in[x] = 1;
			d[x] = 0;
		}
		bool can = 0;
		while (q.size() && can==0) {
			int x = q.front(); q.pop();
			in[x] = 0;
			for (auto p : edge[x]) {
				int nxt = p.first, w = p.second;
				if (d[nxt] > d[x] + w) {
					d[nxt] = d[x] + w;
					if (in[nxt] == 0) {
						in[nxt] = 1;
						q.push(nxt);
					}
					if (++upd[nxt]==N) {
						can = 1;
						break;
					}
				}
			}
		}
		printf("%s\n",can? "YES":"NO");
	}

	return 0;
}
