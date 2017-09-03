//category : dp



#include <stdio.h>

int A[1001];
int D1[1001];
int D2[1001];
int max(int a, int b){ return a < b ? b : a; }
int main(){
	int N;
	int i,j;
	int ans = 0;
	scanf("%d",&N);
	for (i = 1; i <= N; i++) scanf("%d",&A[i]);
	for (i = 1; i <= N; i++){
		D1[i] = 1;
		for (j = 1; j < i; j++)
			if (A[j] < A[i]) D1[i] = max(D1[i], D1[j] + 1);
		
	}
	for (i = N; i >= 1; i--){
		D2[i] = 1;
		for (j = N; i < j;j--)
			if (A[j]<A[i]) D2[i] = max(D2[i], D2[j] + 1);
	}
	for (i = 1; i <= N; i++) ans = max(ans, D1[i] + D2[i]-1);
	printf("%d",ans);
	return 0;
}
