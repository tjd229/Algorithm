//graph, MCMF, SPFA

#include <stdio.h>
const int SRC = 0;
const int RIGHT = 11;
const int SINK = RIGHT + RIGHT + 1;
struct Edge{
	int to, cost, cap;
	Edge *r;
	Edge(int a1, int a2, int a3, Edge *a4) :to(a1), cost(a2), cap(a3), r(a4){}
};
template <typename T>
struct Vector{
	int base;
	int sz;
	T *e;

	void add(T x){
		if (sz == 0){
			base = 32;
			e = new T[base];
		}
		if (sz == base){
			base <<= 1;
			T *t = new T[base];
			for (int i = 0; i < sz; i++) t[i] = e[i];
			delete[] e;
			e = t;
		}
		e[sz++] = x;
	}
	T& operator[](int ix){ return e[ix]; }
};
Vector<Edge*> edge[SINK + 1];
int from[SINK + 1];
Edge* path[SINK + 1];
int d[SINK + 1];

void add_edge(int u, int v, int cap, int cost){
	Edge *uv = new Edge(v, cost, cap, NULL);
	Edge *vu = new Edge(u, -cost, 0, uv);
	uv->r = vu;
	edge[u].add(uv);
	edge[v].add(vu);
}
bool spfa(int &f, int &c){
	int inq[SINK + 1] = { 0 };
	int i, j;
	int curr;
	Vector<int> q;
	q.sz = 0;
	from[0] = from[SINK] = -1;
	for (i = 0; i <= SINK; i++) d[i] = 1e9;
	d[0] = 0;
	q.add(0);
	inq[0] = 1;
	for (i = 0; i < q.sz; i++){
		curr = q[i];
		inq[curr] = 0;
		//printf("%d,%d,%d\n",i,q.sz,curr);
		for (j = 0; j < edge[curr].sz; j++){
			Edge *e = edge[curr][j];
			int to = e->to;
			if (e->cap > 0 && d[to]>d[curr] + e->cost){
				d[to] = d[curr] + e->cost;
				from[to] = curr;
				path[to] = e;
				if (!inq[to]){
					q.add(to);
					inq[to] = 1;
				}
			}
		}
	}
	if (from[SINK] < 0) return false;
	int mf = 1e9;
	curr = SINK;
	while (from[curr] >= 0){
		if (mf > path[curr]->cap)
			mf = path[curr]->cap;
		curr = from[curr];
	}
	curr = SINK;
	while (from[curr] >= 0){
		path[curr]->cap -= mf;
		path[curr]->r->cap += mf;
		curr = from[curr];
	}
	f += mf;
	c += mf*d[SINK];
	return true;
}
int flow(){
	int cost = 0;
	int flow = 0;
	while (spfa(flow, cost));
	return cost;
}
int main(){
	int C;
	int i,j;
	int s;
	for (scanf("%d", &C); C--;){
		for (i = 1; i <= 11; i++){
			for (j = 1; j <= 11; j++){
				scanf("%d",&s);
				if (s) add_edge(i, RIGHT + j, 1, -s);
			}
			add_edge(SRC, i, 1, 0);
			add_edge(RIGHT+i,SINK, 1, 0);
		}
		printf("%d\n",-flow());
		for (i = 0; i <= SINK; i++){
			for (j = 0; j < edge[i].sz; j++){
				Edge *e = edge[i][j];
				delete e;
			}
			delete[] edge[i].e;
			edge[i].sz = 0;
		}
	}
}
