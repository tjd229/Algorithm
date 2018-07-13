//graph, NF
#include <stdio.h>
const int SRC = 0;
const int RIGHT = 500;
const int SINK = RIGHT + RIGHT + 1;
struct Edge{
	int to;
	int cap;
	Edge* r;
	Edge(int a1, int a2, Edge *a3) :to(a1), r(a3), cap(a2){}
};
template <typename T>
struct Vector{
	T ** e;
	int sz;
	int base;
	void add(T *x){
		if (sz == 0){
			base = 32;
			e = new T*[base];
		}
		if (sz == base){
			base <<= 1;
			T **t = new T*[base];
			for (int i = 0; i < sz; i++) t[i] = e[i];
			delete []e;
			e = t;
		}
		e[sz++] = x;
	}
	T& operator[](int ix){
		return *e[ix];
	}
};
Vector<Edge> edge[SINK+1];
int visit[SINK + 1];
void add_edge(int u, int v, int cap){
	Edge *uv = new Edge(v, cap, NULL);
	Edge *vu = new Edge(u, 0, uv);
	uv->r = vu;
	edge[u].add(uv);
	edge[v].add(vu);
}
int min(int a, int b){ return a < b ? a : b; }
int dfs(int ix,int stamp,int c){
	if (visit[ix] == stamp) return 0;
	visit[ix] = stamp;
	if (ix == SINK) return c;
	int flow=0;
	for (int i = 0; i < edge[ix].sz; i++){
		Edge *e = &edge[ix][i];
		if (e->cap <= 0) continue;
		flow = dfs(e->to, stamp, min(c, e->cap));
		if (flow > 0){
			e->cap -= flow;
			e->r->cap += flow;
			return flow;
		}
	}
	return 0;
}
int flow(){
	int f = 0;
	int tot = 0;
	int stamp = 1;
	do{
		f = dfs(SRC, stamp++, RIGHT + RIGHT);
		tot += f;
	} while (f != 0);
	return tot;
}
int main(){
	int n, k;
	int x, y;
	for (scanf("%d%d", &n, &k); k--;){
		scanf("%d%d",&x,&y);
		add_edge(x, RIGHT+y, 1);
	}
	for (int i = 1; i <= n; i++){
		add_edge(SRC, i, 1);
		add_edge(RIGHT+i, SINK, 1);
	}
	printf("%d",flow());
	return 0;
}
