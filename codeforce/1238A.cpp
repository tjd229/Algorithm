//math
#include <stdio.h>
#define ll long long
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		ll x, y; scanf("%I64d%I64d", &x, &y);
		ll d = x - y;
		
		if (d == 1) printf("NO\n");
		else {
			printf("YES\n");
		}
	}
	
	return 0;
}