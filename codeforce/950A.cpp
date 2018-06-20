//category : math

#include <stdio.h>
int min(int a, int b){ return a < b ? a : b; }
int main(){
	int l, r, a;
	int ans;
	scanf("%d%d%d",&l,&r,&a);
	if (l > r) l ^= r ^= l ^= r;
	ans = l;
	r -= l;

	int re = min(r, a);
	if (r > a){
		ans += a;
	}
	else{//r<a
		a -= r;
		ans += r + (a >> 1);
	}
	
	
	printf("%d",ans<<1);

	return 0;
}
