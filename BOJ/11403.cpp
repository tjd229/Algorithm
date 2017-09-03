//category : graph, floyd

#include <stdio.h>

int graph[100][100];

int main(){
	int N;
	int i, j,k;
	scanf("%d",&N);
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) scanf("%d",&graph[i][j]);
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			for (k = 0; k < N; k++){
				graph[j][k] |= graph[j][i] & graph[i][k];
			}
		}
	}
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++) printf("%d ", graph[i][j]);
		printf("\n");
	}


	return 0;
}