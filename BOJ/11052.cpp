//category : dp

#include <stdio.h>

int p[10001];
int d[10001];
int max(int a, int b){
	return a > b ? a : b;
}
int main(){

	int T;
	int N;
	scanf("%d",&N);
	int i,j;
	for (i = 1; i <= N; i++)
		scanf("%d",&p[i]);
	d[1] = p[1];
	for (i = 2; i <= N; i++){
		d[i] = p[i];
		for (j = 1; j < i; j++)
			d[i] = max(d[i], d[i - j] + p[j]);
	}
	printf("%d",d[N]);
	return 0;
}