//graph, LCA
#include "Ioi.h"
#include <vector>
#include <memory.h>
using namespace std;
int rpos[10000];
vector<int> iedge[10000];
vector<int> ig[10000];
int ip[10000][15], id[10000];
int vis[10000];

int iclimb(int x, int d) {
	int step = 0;
	while (d) {
		if (d & 1) x = ip[x][step];
		d >>= 1;
		++step;
	}
	return x;
}
int ilca(int a, int b) {
	if (id[a] < id[b]) b = iclimb(b, id[b] - id[a]);
	else if (id[a] > id[b]) a = iclimb(a, id[a] - id[b]);
	if (a == b) return a;
	for (int j = 14; j >= 0; --j) {
		if (ip[a][j] != ip[b][j]) {
			a = ip[a][j];
			b = ip[b][j];
		}
	}
	return ip[a][0];
}
inline int idist(int a, int b) {
	return id[a] + id[b] - (id[ilca(a, b)] << 1);
}
void make_itree(int x, vector<int> &g) {//init dfs
	if (g.size() < 60) g.push_back(x);
	rpos[x] = -1;
	for (int i = 0; i < iedge[x].size(); ++i) {
		int to = iedge[x][i];
		if (rpos[to] < 0) {
			iedge[x][i] = -1;
			continue;
		}
		
		id[to] = id[x] + 1;
		ip[to][0] = x;
		make_itree(to, g);
	}

}
void idfs(int x) {
	if (rpos[x] != -1) return;
	
	int p = ip[x][0];
	idfs(p);
	ig[x] = ig[p];
	int mx = 0;
	int rep = 0;
	for (int i = 0; i < ig[x].size(); ++i) {
		if (ig[x][i] == p) continue;
		int dist = idist(x, ig[x][i]);
		if (dist > mx) {
			mx = dist;
			rep = i;
		}
	}
	rpos[x] = rpos[ig[x][rep]];
	ig[x][rep] = x;
}
long long cage(int x,int from) {
	long long mem = 0;
	//printf("dfs:%d\n",x);
	for (auto to : iedge[x]) {
		if (to < 0 || to==from) continue;
		if (!vis[to]) continue;
		long long r = Move(to);
		mem |= (r <<rpos[to]);
		mem |= cage(to,x);
		//printf("dfs:%d\n", x);
	}
	int p = ip[x][0];
	if (p>=0 && vis[p] && p!=from) {
		int p = ip[x][0];
		long long r = Move(p);
		mem |= (r << rpos[p]);
		mem |= cage(p,x);
		//printf("dfs:%d\n", x);
	}
	vis[x] = 0;
	if (from >= 0) {
		long long r = Move(from);
		mem |= (r << rpos[from]);
	}
	return mem;
}
long long Ioi(int N, int M, int A[], int B[], int P, int V, int T) {
	memset(ip, -1, sizeof(ip));
	for (int i = 0; i < M; ++i) {
		iedge[A[i]].push_back(B[i]);
		iedge[B[i]].push_back(A[i]);
	}
	make_itree(0, ig[0]);
	for (int i = 0; i < ig[0].size(); ++i) {
		int x = ig[0][i];
		ig[x] = ig[0];
		rpos[x] = i;
	}
	
	for (int j = 1; j < 15; ++j) for (int i = 0; i < N; ++i) ip[i][j] = ip[ip[i][j - 1]][j - 1];
	idfs(P);
	for (auto x : ig[P]) vis[x] = 1;
	
	return cage(P, -1);
}
