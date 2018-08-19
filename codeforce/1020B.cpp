//graph

#include <stdio.h>
#include <memory.h>
int hole[1001];
int p[1001];
int dfs(int ix){
	if (hole[ix] == 1) return ix;
	hole[ix]++;
	return dfs(p[ix]);
}
int main(){
	int i;
	int n;
	for (scanf("%d", &n), i = 1; i <= n; i++){
		scanf("%d",p+i);
	}
	for (i = 1; i <= n; i++){
		memset(hole,0,sizeof(hole));
		hole[i] = 1;
		printf("%d ",dfs(p[i]));
	}
	return 0;
}
