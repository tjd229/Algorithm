//category : graph


#include <stdio.h>
int edge[501][501];
int visit[501];
int nn, nm;
int n, m;
void dfs(int ix, int stamp){
	if (visit[ix] == stamp) return;
	visit[ix] = stamp;
	nn++;
	for (int i = 1; i <= n; i++){
		if (edge[ix][i]){
			edge[ix][i] = edge[i][ix] = 0;
			nm++;
			dfs(i, stamp);
		}
	}
}
int main(){
	int tc = 1;
	int u, v;
	int T;
	int i;
	while (scanf("%d%d", &n, &m)){
		if (n == 0 && m == 0) break;
		T = 0;
		while (m--){
			scanf("%d%d", &u, &v);
			edge[u][v] = edge[v][u] = 1;
		}
		for (i = 1; i <= n; i++){
			nn = nm = 0;
			dfs(i, tc);
			if (nn - 1 == nm) T++;
		}
		printf("Case %d: ", tc);
		switch (T){
		case 0:
			printf("No trees.\n");
			break;
		case 1:
			printf("There is one tree.\n");
			break;
		default:
			printf("A forest of %d trees.\n", T);
		}
		tc++;
	}
}