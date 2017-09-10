//category : graph, MST, djs, LCA


#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAX(a,b) a<b? b:a
using namespace std;

struct Edge{
	int a, b, c;
	int sz;
	bool operator<(Edge e) const{
		return c < e.c;
	}
	int get_v(int curr){
		if (curr == a) return b;
		return a;
	}
}edge[100000];
const int e = 17;
int n, m;
int p[100001];
int logp[100001][1 + e];
int max_tmp[100001][1 + e];
int sz[100001];
bool visit[100001];
int depth[100001];
int tmp;
vector<int > adj_list_ix[100001];
int find(int a){
	if (a != p[a]) p[a] = find(p[a]);
	return p[a];
}
bool join(int a,int b){
	a = find(a);
	b = find(b);
	if (a == b) return false;
	p[b] = a;
	sz[a] += sz[b];
	return true;
}
void kruskal(){
	int ix = 0;
	do{
		if (join(edge[ix].a, edge[ix].b)){
			edge[ix].sz = sz[find(edge[ix].a)];
			if (tmp < edge[ix].c) tmp = edge[ix].c;
			adj_list_ix[edge[ix].a].push_back(ix);
			adj_list_ix[edge[ix].b].push_back(ix);
		}
		if (edge[ix].sz == n) return;
		ix++;
	} while (ix<m);
}
void dfs(int ix){
	if (visit[ix]) return;
	visit[ix] = true;
	int edge_ix;
	int to;
	for (int i = 0; i < adj_list_ix[ix].size(); i++){
		edge_ix = adj_list_ix[ix][i];
		if (tmp < edge[edge_ix].c) continue;
		to = edge[edge_ix].get_v(ix);
		if (!visit[to]){
			depth[to] = depth[ix] + 1;
			logp[to][0] = ix;
			max_tmp[to][0] = edge_ix;
			dfs(to);
		}
	}
	
}
void print_ans(int edge_ix){
	if (edge_ix < 0){
		printf("0 1\n");
		return;
	}
	printf("%d %d\n", edge[edge_ix].c, edge[edge_ix].sz);
}
void query(int a,int b,int edge_ix){
	if (a == b){
		print_ans(edge_ix);
		return;// a;

	}
	int k = 1 << e;
	int j = e;
	for (; j >= 0; j--, k >>= 1){
		if (logp[a][j] != logp[b][j]){
			if (edge_ix < max_tmp[a][j]) edge_ix = max_tmp[a][j];
			if (edge_ix < max_tmp[b][j]) edge_ix = max_tmp[b][j];
			a = logp[a][j];
			b = logp[b][j];
		}

	}
	if (edge_ix < max_tmp[a][0]) edge_ix = max_tmp[a][0];
	if (edge_ix < max_tmp[b][0]) edge_ix = max_tmp[b][0];
	print_ans(edge_ix);
	//a = logp[a][0];
	//return a;
}
int climb(int ix,int d,int &edge_ix){
	int k = 0;
	while (d != 0){
		if (d & 1){
			if (edge_ix < max_tmp[ix][k]) edge_ix = max_tmp[ix][k];
			ix = logp[ix][k];
			
		}
		k++;
		d >>= 1;
	}
	return ix;
}
int main(){
	int i,j,k;
	int x, y;
	int Q;
	int lca;
	scanf("%d%d",&n,&m);
	for (i = 0; i < m; i++){
		scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].c);	
		edge[i].sz = 1;
	}
	for (i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
	sort(edge, edge + m);
	kruskal();

	for (i = 1; i <= n;i++)
		dfs(i);
	for (j = 1, k = 2; j < e+1; j++, k <<= 1){
		for (i = 1; i <= n; i++){
			logp[i][j] = logp[logp[i][j - 1]][j - 1];
			max_tmp[i][j] = MAX(max_tmp[i][j - 1], max_tmp[logp[i][j-1]][j - 1]);
		}

	}
	for (scanf("%d", &Q); Q--;){
		scanf("%d%d",&x,&y);
		if (find(x) != find(y)){
			printf("-1\n");
			continue;
		}
		k = -1;
		if (depth[x] < depth[y]) y = climb(y, depth[y] - depth[x],k);
		if (depth[x] > depth[y]) x = climb(x, depth[x] - depth[y],k);
		query(x,y,k);
	}
	

	return 0;
}

