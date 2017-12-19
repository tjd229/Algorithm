//category : graph, MCMF, SPFA

#include <stdio.h>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define SRC 0
#define RIGHT 400
#define SINK RIGHT+RIGHT+1
using namespace std;
struct Edge{
	int to;
	int cap;
	int r;
	int cost;
};
vector<Edge> edge[SINK + 1];
int d[SINK + 1];
pii from[SINK + 1];
void add_edge(int u, int v, int cap, int cost){
	Edge e;
	edge[u].push_back(e);
	edge[v].push_back(e);
	Edge*fe = &edge[u][edge[u].size() - 1];
	Edge*be = &edge[v][edge[v].size() - 1];
	fe->to = v;
	fe->cap = cap;
	fe->cost = cost;
	fe->r = edge[v].size() - 1;
	be->to = u;
	be->cap = 0;
	be->cost = -cost;
	be->r = edge[u].size() - 1;
}
bool spfa(int &flow, int &cost){
	bool inq[SINK + 1] = { 0 };
	fill(d, d + SINK + 1, (int)1e9);
	queue<int> q;
	q.push(SRC);
	inq[SRC] = true;
	d[SRC] = 0;
	from[SRC]=from[SINK] = { -1, -1 };
	int curr,to;
	int cap=1e9;
	int i;
	Edge*e;
	while (!q.empty()){
		curr = q.front();
		q.pop();
		inq[curr] = false;
		for (i = 0; i < edge[curr].size(); i++){
			e = &edge[curr][i];
			to = e->to;
			if (e->cap > 0 &&
				d[to] > d[curr] + e->cost){
				d[to] = d[curr] + e->cost;
				from[to] = { curr, i };
				if (!inq[to]){
					q.push(to);
					inq[to] = true;
				}
			}
		}
	}
	if (from[SINK].first < 0) return false;
	curr = SINK;
	
	do{
		if (cap > edge[from[curr].first][from[curr].second].cap)
			cap = edge[from[curr].first][from[curr].second].cap;
		curr = from[curr].first;
	} while (curr != SRC);
	curr = SINK;
	do{
		e = &edge[from[curr].first][from[curr].second];
		e->cap -= cap;
		edge[e->to][e->r].cap += cap;
		curr = from[curr].first;
	} while (curr != SRC);
	//
	flow += cap;
	cost += cap*d[SINK];
	return true;
}
pii flow(){
	int flow, cost;
	flow = cost = 0;
	while (spfa(flow,cost));
	return{ flow, cost };
}
int main(){
	int i, j, k;
	int N, M;
	int job, cost;
	for (scanf("%d%d", &N, &M), i = 1; i <= N; i++){
		scanf("%d", &k);
		while (k--){
			scanf("%d%d", &job, &cost);
			add_edge(i, RIGHT + job, 1, cost);
		}
		add_edge(SRC,i,1,0);
	}
	for (i = 1; i <= M;i++)
		add_edge(RIGHT+i, SINK,1, 0);
	pii p = flow();
	printf("%d\n%d",p.first,p.second);
	return 0;
}