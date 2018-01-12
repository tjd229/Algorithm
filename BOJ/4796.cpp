//category : greedy

#include <stdio.h>
int main(){
	int L, P, V;
	int tc = 1;
	int ans,r;
	while (scanf("%d%d%d",&L,&P,&V)){
		if (L*P*V == 0) break;
		ans = L*(V / P);
		r = V%P;
		ans += L < r ? L : r;
		printf("Case %d: %d\n",tc++,ans);
	}
	return 0;
}
