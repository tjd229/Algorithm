//category : graph, floyd


#include <stdio.h>
#define MAXVAL 10000001
int graph[101][101];

int main(){
	int n, m;
	int u, v, c;
	int i,j,k;
	scanf("%d%d", &n, &m);
	
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			graph[i][j] = MAXVAL;		
		}
	}
	for (i = 0; i < m; i++){
		scanf("%d%d%d",&u,&v,&c);
		if (graph[u][v]==MAXVAL||graph[u][v]>c)
			graph[u][v] = c;
	}

	for (k = 1; k <= n; k++){
		for (i = 1; i <= n; i++){
			for (j = 1; j <= n; j++){
				if (i!=j&&graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			if (graph[i][j] == MAXVAL) graph[i][j] = 0;
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}
