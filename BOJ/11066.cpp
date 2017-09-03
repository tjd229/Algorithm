//category : dp

#include <stdio.h>
#include <memory.h>

int f[501];
int s[501];
int d[501][501];
int c[501][501];
int min(int a, int b){ return a < b ? a : b; }
int merge(int i, int j){

	if (c[i][j] > 0) return d[i][j];
	int k;
	d[i][j] = 2e9;
	c[i][j] = 1;
	for (k = i; k < j; k++) d[i][j] = min(d[i][j], merge(i, k) + merge(k + 1, j) + s[j] - s[i - 1]);

	return d[i][j];
}
int main(){
	int T;
	int K;
	int i;
	for (scanf("%d", &T); T--;){
		memset(c,0,sizeof(c));
		scanf("%d",&K);
		for (i = 1; i <= K; i++){
			scanf("%d", &f[i]);
			s[i] = s[i - 1] + f[i];
			
			c[i][i] = 1;
		}
		printf("%d\n",merge(1,K));
	}

	

	return 0;
}

