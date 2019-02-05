//implementation
#include <stdio.h>
int l[51];
int r[51];
int val[51];
int main() {
	int i, N, M;
	int cnt = 0;
	l[1] = r[1] = val[1] = 1;
	for (scanf("%d%d", &N, &M), i = 2; i <= N; ++i) {
		l[i] = i - 1;
		r[i] = 1;
		val[i] = i;
		r[l[i]] = i;
		l[1] = i;
	}
	int cur = 1;
	while (M--) {
		int target;
		scanf("%d",&target);
		int left, right;
		left = right = 0;
		for (int it = cur; val[it] != target; ++left) it = l[it];
		for (int it = cur; val[it] != target; ++right) it = r[it];
		cnt += left < right ? left : right;
		cur = r[target];
		r[l[target]] = r[target];
		l[r[target]] = l[target];
	}
	printf("%d",cnt);
	return 0;
}