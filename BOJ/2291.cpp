//dp
#include <stdio.h>
#include <memory.h>
#define ll long long
ll d[11][221][221];
int N, M, K;
ll seq(int n,int sum,int x) {
	if (n == N) return sum==M;
	ll &ref = d[n][sum][x];
	if (ref != -1) return ref;
	ref = 0;
	for (int i = x;sum+i<=M; ++i) 
		ref += seq(n + 1, sum + i, i);
	//if(ref!=0)
	//printf("%d,%d,%d:%lld\n",n,sum,x,ref);
	return ref;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d%d%d",&N,&M,&K);
	seq(0, 0, 1);
	int sum = 0;
	int last = 1;
	for (int i = 1; i < N; ++i) {
		sum += last;
		for (int x=last;;++x,++sum) {
			if (d[i][sum][x]<=0|| K <= d[i][sum][x]) {
				last = x;
				printf("%d ",x);
				break;
			}
			K -= d[i][sum][x];
		}
	}printf("%d",M-sum);
	return 0;
}