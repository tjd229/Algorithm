//category : graph

#include <stdio.h>
int edge[5001];
int num[5001];
int cnt;
bool dfs(int ix){
	num[ix] = ++cnt;
	if (num[edge[ix]]) return cnt - num[edge[ix]] == 2;
	return dfs(edge[ix]);
}
int main(){
	int i;
	int n;
	for (scanf("%d", &n), i = 1; i <= n; i++) scanf("%d", edge+i);
	for (i = 1; i <= n; i++){
		if (num[i] == 0 && dfs(i)){
			printf("YES");
			return 0;
		}
		else cnt += 3;
	}
	printf("NO");
	return 0;
}
