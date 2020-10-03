//graph, SPFA

#include <stdio.h>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;
const int inf = 1e9;
long long d[501];
int upd[501];
int mat[501][501];
bool inq[501];
vector<pii > edge[501];
int main() {
	int i, N, M;
	for (scanf("%d%d", &N, &M), i = 1; i <= N; ++i) {
		d[i] = inf;
		for (int j = 1; j <= N; ++j) mat[i][j]=inf;
	}
	for (i = 0; i < M; ++i) {
		int A, B, C; scanf("%d%d%d",&A,&B,&C);
		if (mat[A][B] > C) mat[A][B] = C;
	}
	for (i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) if (mat[i][j] < inf) edge[i].push_back({j,mat[i][j]});
	queue<int> q; q.push(1);
	d[1] = 0;
	inq[1] = 1;
	bool ans = 1;
	while (q.size() && ans) {
		int x = q.front(); q.pop();
		inq[x] = 0;
		for (auto p : edge[x]) {
			int nxt = p.first, w = p.second;
			if (d[nxt] > d[x] + w) {
				d[nxt] = d[x] + w;
				if (inq[nxt] == 0) {
					inq[nxt] = 1;
					q.push(nxt);
					if (++upd[nxt] == N) {
						ans = 0;
						break;
					}
				}
				
			}
		}
	}
	if (!ans) printf("-1");
	else {
		for (i = 2; i <= N; ++i) printf("%d\n",d[i]==inf? -1:d[i]);
	}
	return 0;
}
