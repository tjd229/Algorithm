//graph

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
const int inf = 2e9;
int dist[10001][2][305];
int block[10001][2][305];
int val[10001];
vector<int> edge[10001];
vector<int> tl;
int N, M, Q, K;
bool bfs(queue<pii > &q,int stamp) {
	int s = tl[stamp - 1];
	int e = tl[stamp];
	int x, t;
	while (q.size()) {
		x = q.front().first;
		t = q.front().second;
		if (t == e) break;
		q.pop();
		int odd = t & 1;
		for (auto to : edge[x]) {
			if (dist[to][1 - odd][stamp] == inf && block[to][1 - odd][stamp] != t + 1) {
				q.push({ to,t + 1 });
				dist[to][1 - odd][stamp] = t + 1;
			}
		}
	}
	return t != s;
}
int main() {
	int i,j;
	int o = 0;
	vector<pii > observe;
	for (scanf("%d%d%d%d", &N, &M, &Q, &K), i = 1; i <= N; ++i) scanf("%d",val+i);
	while (M--) {
		int X, Y;
		scanf("%d%d",&X,&Y);
		edge[X].push_back(Y);
		edge[Y].push_back(X);
	}
	for (i = 1; i <= N; ++i) for (j = 0; j <305; ++j) dist[i][0][j] = dist[i][1][j] = inf;
	for (i = 0; i < Q; ++i) {
		int T, X;
		scanf("%d%d",&T,&X);
		observe.push_back({T,X});
	}
	sort(observe.begin(), observe.end());
	dist[1][0][0] = 0;
	block[1][0][0] = -1;
	tl.push_back(0);
	int p = 0;
	for (auto q : observe) {
		if ( tl.back() != q.first) tl.push_back(q.first);
	}
	if (tl.back()!=K ) tl.push_back(K);
	for (i = 1; i < tl.size(); ++i) {
		queue<pii > q;
		int t = tl[i];
		while (o < Q&& t == observe[o].first) {
			block[observe[o].second][t&1][i]=t;
			++o;
		}
		for (j = 1; j <= N; ++j) {
			if (dist[j][p & 1][i - 1] <= p && block[j][p & 1][i - 1] != p) {
				dist[j][p & 1][i] = p;
				q.push({j,p});
			}
		}
		if (!bfs(q, i)) {
			puts("-1");
			return 0;
		}
		p = t;
	}
	int ans = -1;
	int cnt = 0;
	int stamp = i - 1;
	for (i = 1; i <= N; ++i) {
		if (dist[i][K & 1][stamp] <= K && block[i][K & 1][stamp] != K) {
			if (ans < val[i]) ans = val[i],cnt=0;
			cnt += ans == val[i];
		}
	}
	printf("%d",ans);
	if (ans > 0) {
		printf(" %d",cnt);
	}
	return 0;
}
