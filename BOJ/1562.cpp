//category : dp

#include <stdio.h>



long long d[101][10][1 << 10];
long long deno = 1000000000;
int main(){

	int n;
	scanf("%d",&n);

	int i,j,k;
	int s = 1 << 10;
	for (i = 1; i < 10; i++){
		d[1][i][1 << i] = 1;
	}
	d[1][0][1 << 0] = 0;
	for (i = 1; i < n; i++){
		for (j = 0; j < 10; j++){
			for (k = 0; k < s; k++){
				d[i][j][k] %= deno;
				if (k&(1 << j)){
					if (j < 9) d[i + 1][j + 1][k | (1 << (j + 1))] += d[i][j][k];
					if (j >0) d[i + 1][j - 1][k | (1 << (j - 1))] += d[i][j][k];
				}
			}
		}
	}
	long long sum = 0;
	for (i = 0; i < 10; i++){
		d[n][i][s - 1] %= deno;
		sum += d[n][i][s - 1];
		sum %= deno;
	}
	printf("%ld",sum);


	return 0;
}

