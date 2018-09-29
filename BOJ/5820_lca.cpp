//graph, d&c, LCA

#include <vector>
#include <stdio.h>
#include <unordered_map>
#define pii pair<int,int>
#define ll long long
using namespace std;
const int lg = 21;
int p[200000][lg + 1];
int depth[200000], visit[200000], sz[200000];
ll dist[200000];
vector<pii > edge[200000];
vector<int> cedge[200000],children[200000];
int N, K;
void dfs(int x){
	for (auto e : edge[x]){
		if (depth[e.first] == 0){
			depth[e.first] = depth[x] + 1;
			dist[e.first] = dist[x] + e.second;
			p[e.first][0] = x;
			dfs(e.first);
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
	else if (depth[a] > depth[b]) a = climb(a, depth[a] - depth[b]);
	if (a == b) return a;
	for (int k = lg; k >= 0; --k){
		if (p[a][k] != p[b][k]){
			a = p[a][k];
			b = p[b][k];
		}
	}
	return p[a][0];
}
ll get_dist(int u, int v){
	return dist[u] + dist[v] - (dist[get_lca(u, v)] << 1);
}
int get_len(int u, int v){
	return depth[u] + depth[v] - (depth[get_lca(u, v)] << 1);
}
int get_sz(int x,int from){
	sz[x] = 1;
	for (auto e : edge[x]){
		int to = e.first;
		if (to != from && visit[to] == 0){
			sz[x] += get_sz(to, x);
		}
	}
	return sz[x];
}
int get_centroid(int x, int from,int half){
	for (auto e : edge[x]){
		int to = e.first;
		if (to == from || visit[to]) continue;
		if (sz[to] > half) return get_centroid(to, x, half);
	}
	return x;
}
int make_ctree(int x){//O(Nxheight)
	int half = get_sz(x, -1)>>1;
	int cen = get_centroid(x, -1, half);
	visit[cen] = 1;
	for (auto e : edge[cen]){
		int to = e.first;
		if (visit[to]) continue;
		int nxt = make_ctree(to);
		cedge[cen].push_back(nxt);//directed
	}
	return cen;
}
void best_path(int x,int& ans){//O(Nxheightxlg)
	unordered_map<ll, int> candi;
	for (auto to : cedge[x]){
		best_path(to, ans);
		for (auto c : children[to]){
			ll d = get_dist(c,x);
			int cnt = candi[K - d]; //(d==k)?
			if (K==d || cnt){
				cnt += get_len(c,x);
				if (ans > cnt) ans = cnt;
			}
		}
		for (auto c : children[to]){
			children[x].push_back(c);
			ll d = get_dist(c, x);
			int len = get_len(c, x);
			int cnt = candi[d];
			if (cnt == 0 || cnt > len) candi[d] = len;
		}
	}
	children[x].push_back(x);
}
int main(){
	int i, j;
	int H0, H1, L;
	for (scanf("%d%d", &N, &K), i = 1; i < N; ++i){
		scanf("%d%d%d",&H0,&H1,&L);
		edge[H0].push_back({ H1, L });
		edge[H1].push_back({ H0, L });
	}
	depth[0] = 1;
	p[0][0] = -1;
	dfs(0);
	for (i = 1; i <=lg; ++i){
		for (j = 0; j < N; j++){
			if (p[j][i - 1] < 0) p[j][i] = -1;
			else p[j][i] = p[p[j][i-1]][i-1];
		}
	}
	int croot = make_ctree(0);
	int ans = 1e9;
	best_path(croot,ans);
	if (ans == int(1e9)) ans = -1;
	printf("%d",ans);
	return 0;
}
