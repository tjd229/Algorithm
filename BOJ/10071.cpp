//graph, djs
#include "game.h"
int n;
int p[1500];
int mat[1500][1500];
int mem[1500][1500];
int sz[1500];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
bool dsu(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	sz[a] += sz[b];
	for (int i = 0; i < n; ++i) {
		int par = find(i);
		mat[i][a] += mat[i][b];
		mat[a][i] += mat[b][i];
		
	}
	p[b] = a;
	return true;
}
void initialize(int n) {
	::n = n;
	for (int i = 0; i < n; ++i) {
		sz[i] = 1; p[i] = i;
		for (int j = 0; j < n; ++j) mem[i][j] = -1;
	}
}

int hasEdge(int u, int v) {
	if (u == v) return 0;
	if (mem[u][v] != -1) return mem[u][v];
	int U = find(u), V = find(v);
	if (U == V) return 0;
	++mat[U][V]; ++mat[V][U];
	if (sz[U] * sz[V] == mat[U][V]) {
		dsu(U, V); mem[u][v] = 1;
		return 1;
	}
	mem[u][v] = 0;
	return 0;
}
