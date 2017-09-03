//category : dp

#include <stdio.h>

int A[1001];
int D[1001];
int max(int a, int b){ return a < b ? b : a; }
int main(){
	int N;
	int i,j;
	int ans = 0;
	scanf("%d",&N);
	for (i = 1; i <= N; i++) scanf("%d",&A[i]);
	for (i = 1; i <= N; i++){
		D[i] = 1;
		for (j = 1; j < i; j++)
			if (A[j] > A[i]) D[i] = max(D[i], D[j] + 1);
		ans = max(D[i], ans);
	}
	printf("%d",ans);
	return 0;
}

