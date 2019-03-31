//math
#include <stdio.h>
#define ll long long
ll nck[32][32];
ll s[32][32];
int ans[32];
int main() {
	int i, j, N, L; ll I;
	for (scanf("%d%d%lld", &N, &L, &I), i = 1; i <= N; ++i) {
		for (j = 1, s[i][0]=nck[i][0] = nck[i][i] = 1; j < i; ++j) {
			nck[i][j] = nck[i - 1][j] + nck[i - 1][j - 1];
			s[i][j] = s[i][j - 1] + nck[i][j];
		}
		s[i][i] = s[i][i - 1] + 1;
		for (j = i + 1; j <= L; ++j) s[i][j] = s[i][j - 1];
		//printf("%d,%lld\n", i, s[i]);
		
	}
	for (i = 0; i <= L; ++i) s[0][i] = 2;
	while (I && L ) {
		--L;
		for (i = 0;; ++i) {
			if (I <= s[i][L]) break;
			I -= s[i][L];
		}
		if (i == 0) {
			ans[i] = (I == 2);
			break;
		}
		//printf("%d,%lld\n",i,I);
		ans[i] = 1;
	}
	while (N--) printf("%d",ans[N]);
	return 0;
}