//category : graph, SCC

#include <stdio.h>
#include <vector>
using namespace std;

int visit[10001];
void dfs(int ix,int stamp,vector<int> *edge){
	if (visit[ix] == stamp) return;
	visit[ix] = stamp;
	for (int i = 0; i < edge[ix].size(); i++)
		dfs(edge[ix][i], stamp, edge);
	edge[0].push_back(ix);
}
int main(){
	int T;
	int tc = 1;
	int i;
	int V, E;
	int A, B;
	int ans;
	for (scanf("%d", &T); tc <= T; tc++){
		scanf("%d%d",&V,&E);
		vector<int> edge[10001];
		vector<int> back[10001];
		while (E--){
			scanf("%d%d",&A,&B);
			edge[A].push_back(B);
			back[B].push_back(A);
		}
		ans = 0;
		for (i = 1; i <= V; i++) dfs(i, tc, edge);
		while (!edge[0].empty()){
			dfs(edge[0].back(), -tc, back);
			edge[0].pop_back();
			ans += (!back[0].empty());
			back[0].clear();
		}
		printf("#%d %d\n",tc,ans);
	}
	return 0;
}
