//dp
#include <stdio.h>
#include <algorithm>
using namespace std;
int d[200001];
int a[200001];
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n, p, k;
		for (scanf("%d%d%d", &n, &p, &k), i = 1; i <= n; ++i) 
			scanf("%d", a + i);
		int ans = 0;
		sort(a + 1, a + 1 + n);
		for (i = 1; i <= n; ++i) {
			d[i] = d[i - 1] + a[i];
			if (i - k >= 0) {
				int bulk = d[i - k] + a[i];
				if (d[i] > bulk) d[i] = bulk;
			}					
		}
		for (i = 1; i <= n; ++i) {
			if (d[i] <= p) ans = i;
		}
		printf("%d\n",ans);
	}
 
	return 0;
}