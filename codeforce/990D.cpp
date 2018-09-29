//graph

#include <stdio.h>
int mat[1000][1000];
int main(){
	int i, j;
	int n, a, b;
	int t = 0;
	scanf("%d%d%d",&n,&a,&b);
	if (a < b) a ^= b ^= a ^= b, ++t;
	if (b != 1 ){
		printf("NO");
		return 0;
	}
	if (a + b == 2 && (n == 2 || n == 3)){
		printf("NO");
		return 0;
	}
	printf("YES\n");
	int c = n - a;
	for (i = 0; i < c; i++) mat[i][i + 1] = mat[i + 1][i] = 1;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++) printf("%d", i==j? 0:mat[i][j] ^ t);
		
		puts("");
	}

	return 0;
}
