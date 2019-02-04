//greedy
#include <stdio.h>
int a[20];
int main() {
	int i;
	int N, S;
	int ans=0;
	for (scanf("%d%d", &N, &S), i = 0; i < N; ++i) scanf("%d",a+i);
	int bnd = 1 << N;
	for (i = 1; i < bnd; ++i) {
		int n = i;
		int tot = 0;
		for (int j = 0; j < N && n; ++j, n>>=1) {
			if (n & 1) tot += a[j];
		}
		ans += (tot == S);
	}printf("%d",ans);
	return 0;
}
