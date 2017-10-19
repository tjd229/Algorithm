//category : graph

#include <stdio.h>
#include <vector>
#define pb push_back
using namespace std;
const int tree = 1e5 + 1;
vector<int> edge[tree];
int visit[tree];
int dist[tree];
int max(int a, int b){ return a < b ? b : a; }
int dfs(int ix,int stamp){
	if (visit[ix] == stamp) return dist[ix];
	visit[ix] = stamp;
	dist[ix] = 1;
	int nxt = 0;
	for (int i = 0; i < edge[ix].size(); i++){
		nxt = max(nxt, dfs(edge[ix][i], stamp));
	}
	dist[ix] += nxt;
	return dist[ix];
}
int main(){
	int i;
	int tc = 1;
	int T;
	int N, E;
	int u, v;
	int ans;
	for (scanf("%d", &T); T--; tc++){
		scanf("%d%d",&N,&E);
		ans = 0;
		while (E--){
			scanf("%d%d",&u,&v);
			edge[u].pb(v);
		}
		for (i = 1; i <= N; i++) ans = max(ans, dfs(i, tc));
		printf("Case %d: %d\n",tc,ans);
		for (i = 1; i <= N; i++) edge[i].clear();
	}

	return 0;
}