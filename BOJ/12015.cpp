//category : ft

#include <stdio.h>
#define BI (1<<20)
int ft[BI + 1];
void update(int ix, int v){
	while (ix <= BI){
		if (ft[ix] >= v) return;
		ft[ix] = v;
		ix += (ix&-ix);
	}
}
int max(int ix){
	int ans = 0;
	while (ix != 0){
		if (ans < ft[ix]) ans = ft[ix];
		ix -= (ix&-ix);
	}
	return ans;
}
int main(){
	int N;
	int buff;
	int t;
	for (scanf("%d", &N); N--;){
		scanf("%d", &buff);
		t = max(buff-1);		
		update(buff, t+1);		
	}
	printf("%d", ft[BI]);

	return 0;
}


