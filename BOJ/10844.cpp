//category : dp

#include <stdio.h>

long long d[101][10];
long long deno = 1000000000;
int main(){
	int i,j;
	int n;
	scanf("%d",&n);
	for (i = 1; i < 10; i++)
		d[1][i] = 1;
	d[1][0] = 0;
	for (i = 2; i < n; i++){
		for (j = 0; j < 10; j++){
			d[i][j] = 0;
		}
	}
	
	for (i = 1; i < n; i++){
		
		for (j = 0; j < 10; j++){
			d[i][j] = d[i][j] % deno;
			if (j < 9) d[i + 1][j + 1]+=d[i][j];
			if (j >0) d[i + 1][j - 1]+=d[i][j];
		}
	}
	
	long long sum = 0;
	for (i = 0; i < 10; i++){
		d[n][i] %= deno;
		sum += d[n][i];
		sum %= deno;
	}
	printf("%ld",sum);
	return 0;
}