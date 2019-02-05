//bs
#include <stdio.h>
int N, M;
int plan[100000];
bool sim(int bnd) {
	int cnt = 1;
	int tot = 0;
	for (int i = 0; i < N; ++i) {
		if (bnd < plan[i]) return 0;
		if (tot + plan[i] > bnd) {
			++cnt;
			tot = 0;
		}
		tot += plan[i];
	}
	return cnt <= M;
}
int main() {
	int i;
	int l = 1;
	int r = 1e9;
	for (scanf("%d%d", &N, &M), i = 0; i < N; ++i) scanf("%d", plan + i);
	while (l <= r) {
		int K = (l + r) >> 1;
		if (sim(K)) r = K - 1;
		else l = K + 1;
	}
	printf("%d",r+1);
	return 0;
}