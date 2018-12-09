//dp

#include <stdio.h>
int d[2];
int main() {
	int i;
	int N, M;	
	scanf("%d%d",&N,&M);
	if (M == 1) printf("%d",N);
	else {
		d[1] = 1;
		for (i = 2; i <= N; ++i) {
			d[i&1] = (d[1-(i&1)] + M - 1) % i + 1;	
		}
		printf("%d",d[N&1]);
	}
	

	return 0;
}
