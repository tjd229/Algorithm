//graph, LCA
#include "Joi.h"
#include <memory.h>
#include <vector>
using namespace std;
int wpos[10000];
vector<int> jedge[10000];
vector<int> jg[10000];
int jp[10000][15],jd[10000];
//climb
//lca
//dist
int jclimb(int x,int d) {
	int step = 0;
	while (d) {
		if (d & 1) x = jp[x][step];
		d >>= 1;
		++step;
	}
	return x;
}
int jlca(int a,int b) {
	if (jd[a] < jd[b]) b = jclimb(b,jd[b]-jd[a]);
	else if (jd[a] > jd[b]) a = jclimb(a,jd[a]-jd[b]);
	if (a == b) return a;
	for (int j = 14; j >= 0; --j) {
		if (jp[a][j] != jp[b][j]) {
			a = jp[a][j];
			b = jp[b][j];
		}
	}
	return jp[a][0];
}
inline int jdist(int a,int b) {
	return jd[a] + jd[b] - (jd[jlca(a,b)]<<1);
}
void make_jtree(int x,vector<int> &g) {//init dfs
	if (g.size() < 60) g.push_back(x);
	wpos[x] = -1;
	for (auto to : jedge[x]) {
		if (wpos[to] < 0) continue;
		jd[to] = jd[x] + 1;
		jp[to][0] = x;
		make_jtree(to, g);
	}	
}
void jdfs(int x) {
	if (wpos[x]!=-1) return;
	int p = jp[x][0];
	jdfs(p);
	jg[x] = jg[p];
	int mx = 0;
	int rep = 0;
	for (int i = 0; i < jg[x].size(); ++i) {
		if (jg[x][i] == p) continue;
		int dist = jdist(x,jg[x][i]);
		if (dist >mx) {
			mx = dist;
			rep = i;
		}
	}
	wpos[x] = wpos[jg[x][rep]];
	jg[x][rep] = x;	
}
void Joi(int N, int M, int A[], int B[], long long X, int T) {
	memset(jp,-1,sizeof(jp));
	for (int i = 0; i < M; ++i) {
		jedge[A[i]].push_back(B[i]);
		jedge[B[i]].push_back(A[i]);
	}
	make_jtree(0,jg[0]);
	for (int i = 0; i < jg[0].size(); ++i) {
		int x = jg[0][i];
		jg[x] = jg[0];
		wpos[x] = i;
	}
	for (int j = 1; j < 15; ++j) for (int i = 0; i < N; ++i) jp[i][j] = jp[jp[i][j - 1]][j - 1];

	for (int i = 0; i < N; ++i) {
		jdfs(i);
		MessageBoard(i,(X>>wpos[i])&1);
	}

}
