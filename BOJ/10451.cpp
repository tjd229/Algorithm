//category : graph



#include <stdio.h>
int edges[10001];
void dfs(int n){
	if (edges[n] == 0) return;
	int v = edges[n];
	edges[n] = 0;
	dfs(v);
}
int main(){
	int T, N;
	int i;
	int ans;
	for (scanf("%d", &T); T--;){
		scanf("%d",&N);
		for (i = 1; i <= N; i++) scanf("%d",&edges[i]);
		ans = 0;
		for (i = 1; i <= N; i++){
			if (edges[i] != 0) ans++, dfs(i);
		}
		printf("%d\n",ans);
	}

	return 0;
}