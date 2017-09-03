//category : dp

#include <stdio.h>


long long d[91][2];

int main(){

	
	int N;
	scanf("%d",&N);
	int i;
	d[1][1] = 1;

	for (i = 2; i <= N; i++){
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
		
	}
		
	
	printf("%lld",d[N][0]+d[N][1]);
	return 0;
}
