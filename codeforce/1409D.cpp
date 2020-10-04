//math, greedy
#include <stdio.h>
#define ll long long
#define END -1
int a[20];
 
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		ll n; int i,s; scanf("%I64d%d",&n,&s);
		int sum = 0;
		for (i = 0;n; ++i) {
			a[i] = n % 10;
			sum += a[i];
			n /= 10;
		}
		int end = i;
		a[end] = END;
		ll cnt = 0;
		ll base = 1;
		i = 0;
		while (sum > s) {
			if (a[i]) {
				int req = 10 - a[i];
				cnt += base * req;
				sum -= a[i]-1;
				++a[i + 1];
			}
			++i;
			base *= 10;
		}
 
		
		printf("%I64d\n",cnt);
	}
 
	return 0;
}