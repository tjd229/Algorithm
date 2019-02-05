//bs
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
int h[1000001];
ll sum[1000001];
int main() {
	int i;
	int N, M;
	for (scanf("%d%d", &N, &M), i = 1; i <= N; ++i) scanf("%d",h+i);
	sort(h + 1, h + 1 + N);
	for (i = 1; i <= N; ++i) sum[i] = sum[i - 1] + h[i];
	int l = 0;
	int r = h[N];
	while (l <= r) {
		int m = (l + r) >> 1;
		int s = lower_bound(h + 1, h + 1 + N, m)-h;
		if (sum[N] - sum[s - 1] - (ll)m*(N - s + 1) < M) r = m - 1;
		else l = m + 1;
	}
	printf("%d",l-1);
	return 0;
}