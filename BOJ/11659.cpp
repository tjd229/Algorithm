//category : implementation

#include <stdio.h>

int d[100001];
int s[100001];

int main(){

	int N, M;
	int i;
	int a, b;
	scanf("%d%d",&N,&M);
	for (i = 1; i <= N; i++){
		scanf("%d", &d[i]);
		s[i] = s[i - 1] + d[i];
	}
	while (M--){
		scanf("%d%d", &a, &b);
		printf("%d\n",s[b]-s[a-1]);
	}


	return 0;
}