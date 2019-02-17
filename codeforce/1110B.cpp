//greedy
#include <stdio.h>
#include <algorithm>
using namespace std;
int b[100001];
int d[100001];
int main() {
	int i;
	int n, m, k;
	int ans = 0;
	for (scanf("%d%d%d", &n, &m, &k), i = 1; i <= n; ++i) {
		scanf("%d",b+i);
		d[i] = b[i] - b[i - 1];
	}
	sort(d + 2, d + 1 + n);
	ans = k;
	for (i = 2; k != n; ++k,++i) 
		ans += d[i];
	printf("%d",ans);
	return 0;
}
