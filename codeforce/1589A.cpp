//math
#include <stdio.h>
#define ll long long
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int u, v; scanf("%d%d",&u,&v);
		ll x = (ll)u*u, y=-((ll)v*v);
		printf("%I64d %I64d\n",x,y);
	}
 
	return 0;
}