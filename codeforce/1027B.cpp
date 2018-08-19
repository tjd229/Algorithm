//math

#include <stdio.h>
#define ll long long
int main(){
	int i, j;
	int n, q;
	int x, y;
	ll bnd = 0;
	scanf("%d%d", &n, &q);
	bnd = (ll)n*n;
	int half = n >> 1;
	ll hbnd = bnd >> 1;
	ll ans;
	hbnd += (bnd & 1);
	while(q--){
		scanf("%d%d",&x,&y);
		ll pos = (y - 1) + (x - 1)*(ll)n;
		//if (n & 1) pos--;
		pos >>= 1;
		ll pad = 0;
		if ((x + y) & 1) pad = hbnd;
		printf("%I64d\n",pos+1+pad);
	}

	return 0;
}
