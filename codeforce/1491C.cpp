//greedy
#include <stdio.h>
int S[5001];
int lazy[5002];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i)scanf("%d",S+i),lazy[i]=0;
		long long ans = 0;
		for (i = 1; i < n; ++i) {
			if (S[i] == 1) {
				lazy[i + 1] += lazy[i];
				continue;
			}
			int to = i + S[i];
			if (to > n) {
				int norm = to - n;
				if (lazy[i] > norm)
					lazy[i] -= norm;
				else {
					ans += norm-lazy[i];
					lazy[i] = 0;
				}
				S[i] -= norm;
				to = n;
			}
			for (int j = to; j >i+1; --j) {
				++lazy[j];
				if (lazy[i]) 
					--lazy[i];				
				else ++ans;
			}
			lazy[i + 1] += lazy[i];
		}
		S[n] -= lazy[n];
		if (S[n] > 1) ans += S[n] - 1;
		printf("%I64d\n",ans);
	}

	return 0;
}