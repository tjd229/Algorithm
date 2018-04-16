//category : graph, MCMF, SPFA

#include <stdio.h>
const int RIGHT = 100;
const int SRC = 0;
const int SINK = RIGHT+RIGHT+1;
struct Edge{
	int to;
	int r;
	int cost;
	int flow;
};
template <typename T>
struct Linear{
	int sz = 0;
	int cap;
	T *e;
	Linear(){ 
		sz = 0;
		cap = 32;
		e = new T[cap];
	}
	T& operator[](int ix) { return e[ix]; }
	void pb(T t){ 
		if (sz == cap){
			cap <<= 1;
			T*tmp = new T[cap];
			for(int i = 0; i < sz; i++) tmp[i] = e[i];
			delete[] e;
			e = tmp;
		}
		e[sz++] = t;
	}
};
Linear<Edge> edge[RIGHT + RIGHT + 2];
Linear<int> q;
int d[RIGHT + RIGHT + 2];
int from[RIGHT + RIGHT + 2],from_e[RIGHT+RIGHT+2];
int N, M;
int A[101], B[101];
void add_edge(int u,int v,int c,int f){
	edge[u].pb({ v, edge[v].sz, c, f });
	edge[v].pb({ u, edge[u].sz-1, -c, 0 });
}
bool spfa(int &flow,int &cost){
	int inq[RIGHT + RIGHT + 2] = { 0 };
	int i;
	d[SRC] = 0;
	for (i = 1; i <= N; i++) d[i] = 1e9;
	for (i = 1; i <= M; i++) d[i + RIGHT] = 1e9;
	d[SINK] = 1e9;
	from[SRC] = from_e[SRC] = -1;
	from[SINK] = from_e[SINK] = -1;
	int front = 0;
	int mf = 1e9;
	int curr;
	q.sz = 0;
	q.pb(SRC);
	d[SRC] = 0;
	inq[SRC] = 1;
	while (front != q.sz){
		curr = q[front++];
		inq[curr] = 0;
		for (i = 0; i < edge[curr].sz; i++){
			Edge *e = &edge[curr][i];
			int to = e->to;
			if (e->flow > 0 && d[to] > d[curr] + e->cost){
				d[to] = d[curr] + e->cost;
				from[to] = curr;
				from_e[to] = i;
				if (!inq[to]){
					inq[to] = 1;
					q.pb(to);
				}
			}
		}
	}
	if (from[SINK] < 0) return false;
	curr = SINK;
	while (from[curr] >= 0){
		if (mf > edge[from[curr]][from_e[curr]].flow)
			mf = edge[from[curr]][from_e[curr]].flow;
		curr = from[curr];
	}
	curr = SINK;
	while (from[curr] >= 0){
		Edge *e = &edge[from[curr]][from_e[curr]];
		e->flow -= mf;
		edge[curr][e->r].flow += mf;
		
		curr = from[curr];
	}
	flow += mf;
	cost += d[SINK]*mf;
	return true;
}
int mcmf(){
	int cost = 0;
	int flow = 0;
	while (spfa(flow, cost));
	return cost;
}
int main(){
	int i,j;
	int C;
	for (scanf("%d%d", &N, &M), i = 1; i <= N; i++){
		scanf("%d", A + i);
		add_edge(SRC, i, 0, A[i]);
	}
	for (i = 1; i <= M; i++){
		scanf("%d", B + i);
		add_edge(RIGHT + i, SINK, 0, B[i]);
	}
	for (i = 1; i <= M; i++){
		for (j = 1; j <= N; j++){
			scanf("%d",&C);
			add_edge(j,RIGHT+i,C,100);
		}
	}
	printf("%d",mcmf());
	return 0;
}
