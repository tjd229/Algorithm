//graph, dijkstra, MCMF, SPFA

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;
const int SRC = 0;
const int RIGHT = 200;
const int SINK = RIGHT + RIGHT+ RIGHT + 1;
const int inf = 1e9;
struct Edge {
	int to, r,cap, cost;
};
pii from[SINK + 1];
vector<Edge> edge[SINK + 1];
int d[SINK + 1], p[SINK + 1], vis[SINK + 1];
int t[201];
int stamp;
void add_edge(int u, int v, int cap, int cost) {
	Edge fr = { v,edge[v].size(),cap,cost };
	Edge bk = { u,edge[u].size(),0,-cost };
	edge[u].push_back(fr);
	edge[v].push_back(bk);
}
void spfa() {
	bool inq[SINK + 1] = { 0 };
	fill(p, p + SINK + 1, inf);
	p[SRC] = 0;
	queue<int> q; q.push(SRC);
	inq[SRC] = 1;
	int cur, to;
	while (q.size()) {
		cur = q.front(); q.pop();
		inq[cur] = 0;
		for (int i = 0; i < edge[cur].size(); ++i) {
			Edge &e = edge[cur][i];
			to = e.to;
			if (e.cap > 0 && p[to] > p[cur] + e.cost) {
				p[to] = p[cur] + e.cost;
				if (!inq[to]) {
					q.push(to);
					inq[to] = 1;
				}
			}
		}
	}

}
bool dijkstra(int stamp, int &flow, int &cost) {
	priority_queue<pii > pq;
	pq.push({ 0,SRC });
	from[SRC] = from[SINK] = { -1,-1 };
	fill(d, d + SINK + 1, inf);
	d[SRC] = 0;
	int cur, to, cap = inf;

	while (pq.size()) {
		cur = pq.top().second; pq.pop();
		if (vis[cur] == stamp) continue;
		vis[cur] = stamp;
		if (cur == SINK) continue;
		for (int i = 0; i < edge[cur].size(); ++i) {
			Edge &e = edge[cur][i];
			to = e.to;
			if (e.cap > 0 && d[to] > d[cur] + e.cost + p[cur] - p[to]) {
				d[to] = d[cur] + e.cost + p[cur] - p[to];
				pq.push({-d[to],to});
				from[to] = { cur,i };
			}
		}
	}
	if (vis[SINK] != stamp) return 0;
	for (int i = 0; i <= SINK; ++i) if (vis[i] == stamp) p[i] += d[i];//
	cur = SINK;
	do {
		cap = min(cap, edge[from[cur].first][from[cur].second].cap);
		cur = from[cur].first;
	} while (cur != SRC);
	cur = SINK;
	do {
		Edge &e = edge[from[cur].first][from[cur].second];
		e.cap -= cap;
		edge[e.to][e.r].cap += cap;
		cost += cap * e.cost;
		cur = from[cur].first;
	} while (cur != SRC);
	flow += cap;
	return 1;
}
pii flow() {
	int flow = 0, cost = 0;
	spfa();
	while (dijkstra(++stamp, flow, cost));
	return { flow,cost };
}
int main() {
	int q;
	for (scanf("%d", &q); q--;) {
		int i, j, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) 
			scanf("%d", t + i);
		int nn = n + n;
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= nn; ++j) {
				int unp = t[i] - j;
				if (unp < 0) unp = -unp;
				add_edge(i, RIGHT + j, 1, unp);
			}
		}
		for (i = 1; i <= n; ++i) add_edge(SRC,i,1,0);
		for (i = 1; i <= nn; ++i) add_edge(i + RIGHT, SINK, 1, 0);
		pii p = flow();
		printf("%d\n",p.second);
		for (i = 0; i <= SINK; ++i) edge[i].clear();
		
		
	}

	return 0;
}