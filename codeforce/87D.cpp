#category : graph, MST, djs

#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;
struct Edge{
	int a, b, d;
	int ix;
	int r;
	ll t;
}road[100000];
int p[100001];
int sz[100001];
int visit[100001];
vector<pii > adj[100001];
int find(int a){
	if (a != p[a]) p[a] = find(p[a]);
	return p[a];
}
void join(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
	sz[a] += sz[b];
}
int dfs(int ix,int stamp){
	visit[ix] = stamp;
	int res = sz[ix];
	int r;
	for (int i = 0; i < adj[ix].size(); i++){
		if (visit[adj[ix][i].first] != stamp){
			r = dfs(adj[ix][i].first, stamp);
			road[adj[ix][i].second].r = r;
			res += r;
		}
	}
	return res;
}
void mrg(int s,int e){
	static int stamp = 0;
	stamp++;
	int i;
	int u, v;
	for (i = s; i < e; i++){
		u = find(road[i].a);
		v = find(road[i].b);
		adj[u].push_back({ v, i });
		adj[v].push_back({u,i});
	}
	for (i = s; i < e; i++){
		u = find(road[i].a);
		if (visit[u] != stamp){
			dfs(u,stamp);
		}
	}
	for (i = s; i < e; i++){
		u = find(road[i].a);
		v = find(road[i].b);
		adj[u].clear();
		adj[v].clear();
	}
	for (i = s; i < e; i++) join(road[i].a, road[i].b);
	for (i = s; i < e; i++){
		u = find(road[i].a);
		road[i].t = (sz[u] - road[i].r)*(ll)road[i].r;
	}
}
int main(){
	int i;
	int n;
	int s, e;
	int last;
	for (scanf("%d", &n), i = 1; i < n; i++){
		scanf("%d%d%d", &road[i].a, &road[i].b, &road[i].d);
		road[i].ix = i;
		p[i] = i;
		sz[i] = 1;
	}
	p[i] = i;
	sz[i] = 1;
	sort(road + 1, road+ n, 
		[](Edge r1, Edge r2){
		return r1.d < r2.d;
	});
	for (i = 1; i < n; ){
		last = road[i].d;
		s = i;
		while (i<n&&last == road[i].d) i++;
		e = i;
		mrg(s, e);
	}
	sort(road + 1, road + n,
		[](Edge r1, Edge r2){
		if (r1.t == r2.t) return r1.ix < r2.ix;
		return r1.t > r2.t;
	});
	s = 1;
	e = 2;
	while (e < n&&road[e].t == road[e - 1].t) e++;
	printf("%I64d %d\n", road[1].t + road[1].t, e - s);
	for (; s < e; s++) printf("%d ",road[s].ix);
	return 0;
}
