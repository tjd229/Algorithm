//math
#include <stdio.h>
#define ll long long 
int main() {
	ll n, p, w, d; 
	ll x, y, z;
	
	scanf("%I64d%I64d%I64d%I64d",&n,&p,&w,&d);
	for (ll y = 0; y < w && p>=0; ++y,p-=d) {
		if (p%w == 0) {
			x = p / w;
			z = n - x - y;
			if (z >= 0) {
				printf("%I64d %I64d %I64d",x,y,z);
				return 0;
			}
		}
	}
	printf("-1");
 
	return 0;
}