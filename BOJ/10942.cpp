//category : dp


#include <stdio.h>

int num[2001];
int d[2001][2001];

int main(){
	
	int N, M;
	int S, E;
	scanf("%d",&N);
	int i,j;
	for (i = 1; i <= N; i++) scanf("%d",&num[i]);
	
	for (i = 0; i < N; i++){
		for (j = 1; j <= N - i; j++){
			if (num[j] != num[j + i]) continue;
			if (i>1 && d[j + 1][j + i - 1] != 1) continue;
			d[j][j + i] = 1;
		}
	}
	for (scanf("%d", &M); M--;) scanf("%d%d", &S, &E), printf("%d\n",d[S][E]);
	return 0;
}