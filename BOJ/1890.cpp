//category : dp


#include <stdio.h>
#include <memory.h>

int a[100][100];
long long d[100][100];
int n;

long long go(int i, int j){
	if (i >= n || j >= n) return 0;
	if (i == n - 1 && j == n - 1) return 1;
	if (a[i][j] == 0) return 0;
	if (d[i][j] >= 0) return d[i][j];
	d[i][j] = go(i + a[i][j], j) + go(i, j + a[i][j]);

	return d[i][j];
}

int main(){

	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	memset(d, -1, 100 * 100*sizeof(long long));
	
	printf("%lld", go(0, 0));


	return 0;
}