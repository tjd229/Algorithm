//category : dp



#include <stdio.h>
int N, M;
long long d[14 * 14 + 1][1 << 14];
bool c[14 * 14 + 1][1 << 14];
long long tile(int n,int s){
	if (n == N*M + 1 && s == 0) return 1;
	if (n > N*M) return 0;
	if (c[n][s]) return d[n][s];

	if (s & 1){
		d[n][s] = tile(n + 1, s >> 1);
	}
	else{
		d[n][s] = tile(n + 1, (s >> 1)|(1<<(M-1)));
		if (n%M != 0&&(s&2)==0) d[n][s] += tile(n + 2, s >> 2);
	}
	d[n][s] %= 9901;
	c[n][s] = true;
	return d[n][s];
}
int main(){
	scanf("%d%d",&N,&M);
	printf("%lld",tile(1,0));
	return 0;
}