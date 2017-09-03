//category : dp



#include <stdio.h>


int d[501][501];
int test(int n,int k){
	if (k == 1) return n;
	if (d[n][k]) return d[n][k];
	int min = n;
	int max = 0;
	for (int i = 2; i < n;i++){
		max = test(i - 1, k - 1);
		if (max < test(n - i, k)) max = test(n - i, k);
		max++;
		if (min > max) min = max;
	}
	d[n][k] = min;
	return min;
}
int main(){
	int N, K;
	scanf("%d%d",&N,&K);
	printf("%d",test(N,K));

	return 0;
}