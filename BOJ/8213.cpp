//graph, bs

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int d[300001];
int dist[300001];
vector<int> edge[300001];
int len, cnt;
void dfs(int ix,int from){
	int i;
	for (auto to : edge[ix]){
		if (to == from) continue;
		dfs(to,ix);
	}
	int l = 0;
	int r = 0;
	vector<int> v;
	if (d[ix]) v.push_back(0);
	for (auto to : edge[ix]){
		if (to == from) continue;
		if (dist[to] < 0) continue;
		v.push_back(dist[to] + 1);
	}
	sort(v.begin(),v.end());
	r = v.size() - 1;
	while (l < r){
		if (v[l] + v[r] <= len + len) l++;
		else r--, cnt++;
	}
	dist[ix] = l == r ? v[l] : -1;
}
int main(){
	int i;
	int a, b;
	for (scanf("%d%d", &n, &m), i = 1; i <= n; i++) scanf("%d",d+i);
	for (i = 1; i < n; i++){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	int l = 0;
	int r = n;
	while (l <= r){
		cnt = 0;
		len = (l + r) >> 1;
		dfs(1, 0);
		if (dist[1] >= 0) cnt++;
		if (cnt <= m) r = len - 1;
		else l = len + 1;
	}
	printf("%d",r+1);
	return 0;
}
