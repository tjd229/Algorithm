//category : ft

#include <stdio.h>
#include <memory.h>
#define BI (1<<18)
int ft[BI + 1];
int ix[100001];
void update(int ix, int diff){
	while (ix <= BI){
		ft[ix] += diff;
		ix += (ix&-ix);
	}
}
int sum(int ix){
	int s=0;
	while (ix > 0){
		s += ft[ix];
		ix -= (ix&-ix);
	}
	return s;
}
int main(){
	int T;
	int m, n;
	int ans = 0;
	int i;
	int buff;
	for (scanf("%d", &T); T--;){
		ans = 0;
		memset(ft, 0, sizeof(ft));
		scanf("%d%d",&n,&m);
		for (i = 1; i <= n; i++){
			ix[i] = m + i;
			update(ix[i], 1);
		}
		do{
			scanf("%d",&buff);
			ans = sum(ix[buff] - 1);
			update(ix[buff], -1);
			update(m, 1);
			ix[buff] = m;
			printf("%d ",ans);
		} while (--m);
		printf("\n");
	}

	return 0;
}


