//category : dp

#include <stdio.h>
int cost[1001][3];
int d[1001][3];

int min(int a, int b){return a < b ? a : b;}
int main(){
	int N;
	scanf("%d",&N);
	int i, j;

	for (i = 1; i <= N; i++){
		scanf("%d%d%d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}
	
	for (i = 1; i <= N; i++){
		for (j = 0; j < 3; j++){
			d[i][j] = min(d[i - 1][(j + 1) % 3], d[i - 1][(j + 2) % 3]) + cost[i][j];
		}
	}
	i = min(d[N][0],d[N][1]);
	printf("%d",min(d[N][2],i));


	return 0;
}