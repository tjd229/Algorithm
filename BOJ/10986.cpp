//category : math



#include <stdio.h>
long long s[1000001];
long long mod[1000];
int main(){
	int N, M;
	scanf("%d%d",&N,&M);
	int i;
	mod[0] = 1;
	for (i = 1; i <= N; i++){
		scanf("%lld",&s[i]);
		s[i] += s[i - 1];
		s[i] %= M;
		mod[s[i]]++;
	}
	long long ans = 0;
	for (i = 0; i < M; i++){
		ans += (mod[i] * (mod[i] - 1)) / 2;
	}
	printf("%lld",ans);
	return 0;
}