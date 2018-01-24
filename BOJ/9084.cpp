//category : dp

#include <stdio.h>
int coin[20];
int d[20][10001];
int visit[20][10001];
int N;
int accnt(int val,int k,int stamp){
	if (val < 0) return 0;
	if (k == 0) return val%coin[k] == 0;
	if (visit[k][val]==stamp) return d[k][val];
	visit[k][val] = stamp;
	int res = 0;
	d[k][val] = accnt(val - coin[k], k, stamp) + accnt(val,k-1,stamp);
	return d[k][val];
}
int main(){
	int T;
	int M;
	int i;
	for (scanf("%d", &T); T--;){
		for (scanf("%d", &N), i = 0; i < N;i++){
			scanf("%d",coin+i);
		}
		scanf("%d",&M);
		printf("%d\n",accnt(M,N-1,T+1));
	}

	return 0;
}
