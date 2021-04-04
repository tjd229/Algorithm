//math, dp
#include <stdio.h>
#define ll long long
int a[1000000], b[1000000];
int d[500000];
int pos[1000001];
int main() {
	int i, n, m; ll k;
	for (scanf("%d%d%I64d", &n, &m, &k), i = 0; i < n; ++i)scanf("%d",a+i);
	for (i = 0; i < m; ++i) scanf("%d",b+i);
	int *A = a, *B = b;
	if (n > m) {
		A = b, B = a;
		n ^= m ^= n ^= m;
	}
	//n<=m
	for (i = 0; i < m; ++i)
		B[i + m] = B[i];
	for (i = 1; i <= m + m; ++i) pos[i] = -1;
	for (i = 0; i < m; ++i) pos[B[i]] = i;
	for (i = 0; i < n; ++i) {
		if (A[i] == B[i]) ++d[0];
		else {
			if (pos[A[i]] != -1) {
				int dst = pos[A[i]];
				if (dst < i) dst += m;
				++d[dst - i];
			}
		}
	}
	for (i = 0; i < m; ++i) d[i] = n - d[i];
	ll ans = 0; ll cnt = 0; int st = 0;
	do {
		if (cnt + d[st] >= k) {//start from st
			for (i = 0; i < n && cnt<k; ++i) {
				if (A[i] != B[st + i]) {
					++cnt;					
				}
				++ans;
			}
			break;//cnt==k
		}
		cnt += d[st];
		st = (st + n) % m;
		ans += n;
	} while (st != 0);
	if (cnt < k) {//cnt is freq. | ans is cyc
		ll div = k / cnt;//cnt is always >1
		if (k%cnt==0) --div;
		ans *= div; cnt *= div; //div is always >1
		do {
			if (cnt + d[st] >= k) {//start from st
				for (i = 0; i < n && cnt < k; ++i) {
					if (A[i] != B[st + i]) {
						++cnt;
					}
					++ans;
				}
				break;//cnt==k
			}
			cnt += d[st];
			st = (st + n) % m;
			ans += n;
		} while (st != 0);
	}
	printf("%I64d",ans);
 
	return 0;
}