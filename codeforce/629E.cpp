//category : graph, LCA

#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
const int lg = 17;
int p[100001][lg + 1];
int depth[100001];
int ucnt[100001], ccnt[100001];
ll ud[100001], cd[100001];
vector<int> edge[100001];
void dfs(int ix,int from){
	int to;
	for (int i = 0; i < edge[ix].size(); i++){
		to = edge[ix][i];
		if (from == to) continue;
		depth[to] = depth[ix] + 1;
		p[to][0] = ix;
		dfs(to, ix);
		ccnt[ix] += ccnt[to] + 1;
		cd[ix] += cd[to];
	}
	cd[ix] += ccnt[ix];
}
void inherit(int ix,int from){
	int to;
	for (int i = 0; i < edge[ix].size(); i++){
		to = edge[ix][i];
		if (from == to) continue;
		ud[to] += ud[ix];
		ucnt[to] += ucnt[ix]+1;
		ud[to] += cd[ix] - cd[to] - ccnt[to] - 1;
		ucnt[to] += ccnt[ix] - ccnt[to] - 1;
		ud[to] += ucnt[to];

		inherit(to, ix);
	}
}
int climb(int ix, int d){
	int k = 0;
	while (d != 0){
		if (d & 1) ix = p[ix][k];
		d >>= 1;
		k++;
	}
	return ix;
}
int get_lca(int a, int b){
	if (a == b) return a;
	int k = lg;
	while (k >= 0){
		if (p[a][k] != p[b][k]){
			a = p[a][k];
			b = p[b][k];
		}
		k--;
	}
	return p[a][0];
}
int main(){
	int i, j;
	int n, m;
	int a, b;
	int u, v;
	for (scanf("%d%d", &n, &m), i = 1; i < n; i++){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1, 0);
	inherit(1, 0);
	for (j = 1; j <= lg; j++){
		for (i = 1; i <= n; i++){
			p[i][j] = p[p[i][j-1]][j-1];
		}
	}

	while (m--){
		scanf("%d%d",&u,&v);
		if (depth[u] > depth[v]) u ^= v ^= u ^= v;
		int diff = depth[v] - depth[u];
		int lca = get_lca(u, climb(v, diff));
		int cnt1, cnt2;
		ll d1, d2,tot,llcnt;
		if (u == lca){
			cnt1 = ccnt[v]+1;
			d1 = cd[v];

			a = climb(v,diff-1);
			cnt2 = ccnt[u] - ccnt[a]-1+ucnt[u]+1;
			d2 = cd[u] - cd[a]-ccnt[a]-1+ud[u];
		}
		else{
			cnt1 = ccnt[v] + 1;
			d1 = cd[v];
			
			cnt2 = ccnt[u] + 1;
			d2 = cd[u];
			diff = depth[u] - depth[lca] + depth[v] - depth[lca];
		}
		llcnt = cnt1 * (ll)cnt2;
		tot = d2*cnt1 + d1*cnt2 + (diff + 1)*llcnt;
		printf("%.9f\n", tot / (float)llcnt);
	}
	return 0;
}
