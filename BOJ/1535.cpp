//category : dp, kanpsack

#include <stdio.h>
int L[21], J[21];
int d[21][100];
int max(int a, int b){
	return a > b ? a : b;
}
int main(){
	int N;
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%d", &L[i]);
	for (i = 1; i <= N; i++)
		scanf("%d", &J[i]);
	for (i = 1; i <= N; i++){
		for (j = 1; j < L[i]; j++)
			d[i][j] = d[i - 1][j];
		for (; j<100; j++){
			d[i][j] = max(d[i - 1][j], d[i - 1][j -L[i]] + J[i]);
			
		}
	}
	printf("%d", d[N][99]);

	return 0;
}
