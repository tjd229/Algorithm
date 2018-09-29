//graph, d&c, LCA

#include <stdio.h>
#include <vector>
using namespace std;
const int lg = 20;
vector<int> edge[100001];
int p[100001][lg + 1];
int depth[100001],sz[100001],visit[100001];
int cdist[100001],cfrom[100001];
int min(int a, int b){ return a < b ? a : b; }
void dfs(int x){
	for (auto to : edge[x]){
		if (depth[to] == 0){
			depth[to] = depth[x] + 1;
			p[to][0] = x;
			dfs(to);
		}
	}
}
int climb(int x, int d){
	int k = 0;
	while (d){
		if (d & 1) x = p[x][k];
		++k;
		d >>= 1;
	}
	return x;
}
int get_lca(int a, int b){
	if (depth[a] < depth[b]) b = climb(b, depth[b] - depth[a]);
	else if (depth[b] < depth[a]) a = climb(a, depth[a] - depth[b]);
	if (a == b) return a;
	for (int k = lg; k >= 0; --k){
		if (p[a][k] != p[b][k]){
			a = p[a][k];
			b = p[b][k];
		}
	}
	return p[a][0];
}
int get_sz(int x,int from){
	sz[x] = 1;
	for (auto to : edge[x]){
		if (from != to&&visit[to] != 1)
			sz[x] += get_sz(to, x);
	}
	return sz[x];
}
int get_centroid(int x,int from,int half){
	for (auto to : edge[x]){
		if (to == from || visit[to]) continue;
		if (sz[to] > half) return get_centroid(to, x, half);
	}
	return x;
}
void make_ctree(int x,int from){
	int half = get_sz(x, 0) >> 1;
	int cen = get_centroid(x, 0, half);
	cfrom[cen] = from;
	visit[cen] = 1;
	for (auto to : edge[cen])
		if (visit[to] == 0) make_ctree(to, cen);
}
int get_dist(int u, int v){
	return depth[u] + depth[v] - (depth[get_lca(u, v)]<<1);
}
void update(int v){
	int x = v;
	while (x){
		cdist[x] = min(cdist[x], get_dist(x, v));
		x = cfrom[x];
	}
}
int red_dist(int v){
	int res = 1e9;
	int x = v;
	while (x){
		res = min(res, cdist[x] + get_dist(x, v));
		x = cfrom[x];
	}
	return res;
}
int main(){
	int i, j;
	int n, m;
	int a, b;
	int t, v;
	for (scanf("%d%d", &n, &m), i = 1; i < n; ++i){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
		cdist[a] = cdist[b] = 1e9;
	}
	depth[1] = 1;
	dfs(1);
	for (i = 1; i <= lg; i++){
		for (j = 1; j <= n; j++){
			p[j][i] = p[p[j][i-1]][i-1];
		}
	}
	make_ctree(1, 0);
	//for (i = 1; i <= n; i++) printf("cp:%d\n",cfrom[i]);
	update(1);
	while (m--){
		scanf("%d%d",&t,&v);
		if (--t){
			printf("%d\n",red_dist(v));
		}
		else{
			update(v);
		}
	}
	return 0;
}
