//greedy
#include <stdio.h>
#define ll long long
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		ll a, b, n,m; scanf("%I64d%I64d%I64d%I64d",&a,&b,&n,&m);
		if (a + b < m + n)
			printf("NO\n");
		else {
			ll d = a - b;
			if (d < 0) d = -d;
			n -= d;
			if (n < 0) n = 0;
			if (n < m) {
				m -= n;
				a -= n, b -= n;
				if (a < 0) a = 0;
				if (b < 0) b = 0;
				ll c = a < b ? a : b;
				printf("%s\n", c >= m ? "YES" : "NO");
				
			}
			else {//n>=m
				ll c = a < b ? a : b;
				printf("%s\n", a >= m ? "YES" : "NO");
			}
			
		}
		
	}
	return 0;
}
