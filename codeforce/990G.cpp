//graph, d&c, math

#include <stdio.h>
#include <vector>
#include <map>
#define ll long long
using namespace std;
int sz[200001], visit[200001];
int a[200001];
ll ans[200001];
vector<int> edge[200001];
map<int, ll> subd,alld;
int gcd(int a, int b){
	if (a > b) a ^= b ^= a ^= b;
	if (a == 0) return b;
	return gcd(b%a, a);
}
int getsz(int x,int from){
	sz[x] = 1;
	for (auto to : edge[x]){
		if (visit[to] == 0 && from != to) sz[x] += getsz(to, x);
	}
	return sz[x];
}
int get_centroid(int x, int from, int half){
	for (auto to : edge[x]){
		if (visit[to] || to == from) continue;
		if (sz[to] > half) return get_centroid(to, x, half);
	}
	return x;
}
void dfs(int x, int from,int d){
	d = gcd(d, a[x]);
	subd[d]++;
	//printf("%d-%d\n",x,d);
	for (auto to : edge[x]){
		if (to != from && visit[to] == 0) dfs(to, x, d);
	}
}
void make_ctree(int x){
	int half = getsz(x, 0) >> 1;
	int c = get_centroid(x, 0, half);
	visit[c] = 1;
	alld.clear();
	alld[a[c]]++;
	//printf("c:%d\n",c);
	for (auto to : edge[c]){
		if (visit[to] == 0){
			subd.clear();
			dfs(to, c,a[c]);
			for (auto i : alld){
				for (auto j : subd){
					int d = gcd(i.first, j.first);
					ans[d] += i.second*j.second;
					//printf("d:%d,%lld\n",d,add);
				}
			}
			for (auto it : subd) alld[it.first] += it.second;
		}
	}
	for (auto to : edge[c]) if (visit[to] == 0) make_ctree(to);
}
int main(){
	int i;
	int n;
	for (scanf("%d", &n), i = 1; i <= n; i++) scanf("%d",a+i),ans[a[i]]++;
	for (i = 1; i < n; i++){
		int x, y;
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	make_ctree(1);
	for (i = 1; i <= 200000; ++i) if (ans[i]) printf("%d %I64d\n",i,ans[i]);
	return 0;
}
