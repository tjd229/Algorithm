//graph, d&c
#include <stdio.h>
#include <vector>
#include <map>
#define pii pair<int,int>
#define ll long long
using namespace std;
int visit[200000], sz[200000];
vector<pii > edge[200000];
map<int, int> mp;
int N, K;
int ans;
int get_sz(int x, int from){
	sz[x] = 1;
	for (auto e : edge[x]){
		int to = e.first;
		if (to != from && visit[to] == 0) sz[x] += get_sz(to, x);
	}
	return sz[x];
}
int get_centroid(int x, int from, int half){
	for (auto e : edge[x]){
		int to = e.first;
		if (to == from || visit[to]) continue;
		if (sz[to] > half) return get_centroid(to, x, half);
	}
	return x;
}
void best_path(int x, int from, int depth, int dist){
	if (dist > K) return;
	int cnt = mp[K - dist];
	if (K == dist || cnt){
		cnt += depth;
		if (ans<0 || ans>cnt) ans = cnt;
	}
	for (auto e : edge[x]){
		int to = e.first;
		if (to != from && visit[to] == 0) best_path(to, x, depth + 1, dist + e.second);
	}
}
void update(int x, int from, int depth, int dist){
	if (dist > K) return;
	int cnt = mp[dist];
	if (cnt == 0 || cnt > depth) mp[dist] = depth;
	for (auto e : edge[x]){
		int to = e.first;
		if (to != from && visit[to] == 0) update(to, x, depth + 1, dist + e.second);
	}
}
void make_ctree(int x){
	int half = get_sz(x, -1) >> 1;
	int cen = get_centroid(x, -1, half);
	visit[cen] = 1;
	//
	mp.clear();
	for (auto e : edge[cen]){
		int to = e.first;
		if (visit[to] == 0){
			best_path(to, cen, 1, e.second);
			update(to, cen, 1, e.second);
		}
	}
	for (auto e : edge[cen]){
		int to = e.first;
		if (visit[to] == 0) make_ctree(to);
	}
}
int main(){
	int i;
	int H0, H1, L;
	for (scanf("%d%d", &N, &K), i = 1; i < N; ++i){
		scanf("%d%d%d", &H0, &H1, &L);
		edge[H0].push_back({ H1, L });
		edge[H1].push_back({ H0, L });
	}
	ans = -1;
	make_ctree(0);
	printf("%d", ans);
	return 0;
}
