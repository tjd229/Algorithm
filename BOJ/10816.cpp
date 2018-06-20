//category : implementation

#include <stdio.h>
const int pad = 1e7;
int cnt[20000001];
int main(){
	int N, M;
	int i;
	int card;
	for (scanf("%d", &N), i = 0; i < N; i++){
		scanf("%d",&card);
		cnt[card + pad]++;
	}
	for (scanf("%d", &M), i = 0; i < M; i++){
		scanf("%d", &card);
		printf("%d ",cnt[card+pad]);
	}
}
