//math, greedy
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100001];
int main() {
	int T;
	for (scanf("%d", &T); T--;) {
		int i, n,x;
		for (scanf("%d%d", &n, &x), i = 1; i <= n; ++i)
			scanf("%d",a+i);
		sort(a + 1, a + 1 + n);
		reverse(a + 1, a + 1 + n);
		long long sum = 0;
		int deno = 0;
		for (i = 1; i <= n; ++i) {
			sum += a[i];
			++deno;
			if (sum / deno < x) {
				--deno;
				break;
			}
		}
		printf("%d\n",deno);
	}
	return 0;
}