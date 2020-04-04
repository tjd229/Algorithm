//greedy
#include <stdio.h>
#define ll long long
ll sum[100001];
ll p[100001];
int l[100001];
int main() {
	int i,n, m;
	for (scanf("%d%d", &n, &m), i = 1; i <= m; ++i) {
		scanf("%d",l+i);
		sum[i] = sum[i - 1] + l[i];
	}
	ll done = 0;
	for (i = 1; i <= m; ++i) {
		p[i] = p[i - 1] + 1;
		int to = p[i] + l[i] - 1;
		if (done < to) done = to;
		if (done > n) {
			p[m] = 0;
			break;
		}
		ll r = sum[m] - sum[i];
		ll ns = n - r+1;
		//printf("%lld,%lld,%lld\n",p[i],r,ns);
		if (p[i] < ns && ns <= done + 1) {
			for (int j = i + 1; j <= m; ++j) {
				p[j] = ns;
				ns += l[j];
			}
			break;
		}
	}
	if (p[m] && p[m]+l[m]-1==n) {
		for (i = 1; i <= m; ++i) printf("%I64d ",p[i]);
	}
	else printf("-1");
	return 0;
}