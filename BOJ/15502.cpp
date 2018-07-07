//reference : https://github.com/jwvg0425/SoftCon/blob/master/1/B.%20K-%EA%B7%A0%EB%93%B1%20%EB%AC%B8%EC%9E%90%EC%97%B4/solution.md
//category : djs

#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;
int p[1001];
int find(int a){
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void join(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}
int main(){
	int i,j;
	int N, M;
	int L, R, K;
	for (i = 1; i <= 1000; i++) p[i] = i;
	for (scanf("%d%d", &N, &M); M--;){
		scanf("%d%d%d",&L,&R,&K);
		for (i = L; i + K <= R; i++)
			join(i, i + K);		
	}
	ll ans = 1;
	for (i = 1; i <= N; i++) if (p[i] == i) ans <<= 1, ans %= mod;
	printf("%lld",ans);
	return 0;
}
