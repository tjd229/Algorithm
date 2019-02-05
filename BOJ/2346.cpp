//implementation
#include <stdio.h>
int l[1001], r[1001];
int val[1001];
int mv[1001];
int main() {
	int i, N;
	for (scanf("%d", &N), i = 1; i <= N; ++i) {
		scanf("%d", mv + i);
		l[i] = i - 1;
		r[i] = l[0];
		val[i] = i;
		r[l[i]] = i;
		l[r[i]] = i;
	}
	l[1] = N;
	r[N] = 1;
	int cur = 1;
	while (--N) {
		printf("%d ",val[cur]);
		int move = mv[val[cur]];
		r[l[cur]] = r[cur];
		l[r[cur]] = l[cur];
		if (move > 0) {
			while (move--) cur = r[cur];
		}
		else {
			while (move++) cur = l[cur];
		}
	}
	printf("%d",val[l[cur]]);
	return 0;
}