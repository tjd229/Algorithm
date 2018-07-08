//category : graph, MCMF, SPFA

#include <stdio.h>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;
const int SRC = 0;
const int RIGHT = 300; //1~300, 301~600
const int SINK = RIGHT + RIGHT + 1;
struct Edge{
	int to;
	int cap;
	int cost;
	int r; //e[v][r]
};
vector<Edge> edge[SINK+1];
pii from[SINK + 1];
int d[SINK + 1];
int A[301], H[301], L[301];
void add_edge(int u,int v,int cap,int cost){
	edge[u].push_back({ v, cap, cost, edge[v].size() });
	edge[v].push_back({ u, 0, -cost, edge[u].size()-1 });
}
bool spfa(int &flow, int &cost){
	
	bool inq[SINK + 1] = { 0 };
	int i;
	fill(d, d + SINK + 1, (int)2e9);
	queue<int> q;
	inq[SRC] = 1;
	q.push(SRC);
	d[SRC] = 0;
	int curr;
	from[SRC] = from[SINK] = { -1, -1 };
	while (q.size()){
		curr = q.front();
		q.pop();
		inq[curr] = false;
		for (i = 0; i < edge[curr].size(); i++){
			Edge *e = &edge[curr][i];
			int to = e->to;
			if (e->cap > 0 && d[to] > d[curr] + e->cost){
				d[to] = d[curr] + e->cost;
				from[to] = { curr, i };
				if (!inq[to]){
					q.push(to);
					inq[to] = 1;
				}
			}
		}
	}
	if (from[SINK].first < 0) return false;

	curr = SINK;
	int cap = 2e9;
	do{
		if (cap > edge[from[curr].first][from[curr].second].cap)
			cap = edge[from[curr].first][from[curr].second].cap;
		curr = from[curr].first;
	} while (curr != SRC);
	curr = SINK;
	do{
		Edge *e = &edge[from[curr].first][from[curr].second];
		e->cap -= cap;
		edge[e->to][e->r].cap += cap;
		curr = from[curr].first;
	} while (curr != SRC);

	flow += cap;
	cost += cap*d[SINK];
	return true;
}
pii flow(){
	int flow, cost;
	flow = cost = 0;
	while (spfa(flow, cost));
	return{ flow, cost };
}
int main(){
	int i,j;
	int N;
	int maxA = 0;
	int winner = 0;
	for (scanf("%d", &N), i = 1; i <= N; i++){
		scanf("%d", A + i);
		if (maxA < A[i]){
			maxA = A[i];
			winner = i;
		}
	}
	for (i = 1; i <= N; i++) scanf("%d", H + i);
	for (i = 1; i <= N; i++){
		scanf("%d", L + i);
		if (i == winner)
			add_edge(SRC, i, L[i], H[i]);
		else{
			add_edge(SRC, i, L[i] - 1, H[i]);
			add_edge(RIGHT+i, SINK, 1, H[i]);
		}		
	}
	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			if (A[i] <= A[j]) continue;
			add_edge(i,RIGHT+j,1,-(A[i]^A[j]));
		}
	}
	pii p = flow();
	printf("%d",-p.second);

	return 0;
}
