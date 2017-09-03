//category : dp

#include <stdio.h>


long long d[1001][10];

int main(){

	
	int N;
	scanf("%d",&N);
	int i,j,k;
	for (i = 0; i < 10; i++)
		d[1][i] = 1;
	for (i = 2; i <= N; i++){
		for (j = 0; j < 10; j++){
			for (k = 0; k <= j; k++)
				d[i][j] += d[i - 1][k], d[i][j] %= 10007;
		}
	}
		
	long long ans = 0;
	for (i = 0; i < 10; i++)
		ans += d[N][i], ans %= 10007;
	
	printf("%lld",ans);
	return 0;
}

