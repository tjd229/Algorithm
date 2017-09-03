//category : dp

#include <stdio.h>


int w[16][16];
int d[1024*64][16];
int main(){

	int n;
	scanf("%d",&n);
	int i, j,k;
	int s;
	int t;
	int min;

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++) scanf("%d",&w[i][j]);
	}
	s = 1 << n;
	for (i = 0; i < s; i++){
		for (j = 0; j < n; j++){
			d[i][j] = 1000000 * n;
		}
	}
	d[1][0] = 0;
	for (i = 0; i < s; i++){
		for (j = 1; j < n; j++){
			if (i&(1 << j)){
				for (k = 0; k < n; k++){
					if (k!=j&&(i&(1 << k))&&w[k][j]){
						t = d[i&~(1 << j)][k] + w[k][j];
						if (t < d[i][j]) d[i][j] = t;
					}
				}
			}
		}
	}
	min = 10000000 * n;
	for (i = 1; i < n; i++){
		t = d[(1 << n) - 1][i] + w[i][0];
		if (t < min) min = t;
	}
	printf("%d",min);


	return 0;
}

