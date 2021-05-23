//greedy
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
int b[200010];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		ll sum = 0;
		for (scanf("%d", &n), i = 1; i <= n + 2; ++i) 
			scanf("%d", b + i);
		
		sort(b + 1, b + n + 3);
		for (i = 1; i <= n; ++i) 
			sum += b[i];
 
		bool flag = 0;
		for (int coin = 0; coin < 2; ++coin) {
			ll l = sum + b[n + 1];
			ll r = b[n + 2];
			ll x = l - r;
			for (i = 1; flag == 0 && i <= n + 1; ++i) {
				if (x == b[i]) flag = 1;
			}
			if (flag) {
				for (i = 1; i <= n + 1; ++i) {
					if (x == b[i]) {
						x = -1;
						continue;
					}
					printf("%d ", b[i]);
				}
				puts("");
				break;
			}
			b[n + 1] ^= b[n + 2] ^= b[n + 1] ^= b[n + 2];
		}
		if (flag == 0)
			printf("-1\n");
	}
 
	return 0;
}