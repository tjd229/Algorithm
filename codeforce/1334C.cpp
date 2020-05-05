//implementation
#include <stdio.h>
#define ll long long
ll a[300001], b[300001];
int head[300001];
ll req[300001];
int main() {
	int T;
	for (scanf("%d", &T); T--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i)
			scanf("%I64d%I64d",a+i,b+i);
		int num_head = 0;
		ll all_head = 0;
		for (i = 1; i < n; ++i) {
			if (b[i] < a[i + 1]) {
				head[i + 1] = T + 1;
				req[i + 1] = a[i + 1] - b[i];
				++num_head;
				all_head += req[i + 1];
			}
		}
		if (b[n] < a[1]) {
			head[1] = 1 + T;
			req[1] = a[1] - b[n];
			++num_head;
			all_head += req[1];
		}
		ll mn = -1;
		for (i = 1; i <= n; ++i) {
			ll num = -1;
			if (head[i] == 1 + T) {
				num = all_head - req[i] + a[i];
			}
			else
				num = a[i] + all_head;
			if (mn<0 || mn>num) mn = num;
		}
		printf("%I64d\n",mn);
 
	}
 
	return 0;
}