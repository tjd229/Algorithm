//bs
#include <stdio.h>
int len[10000];
int K, N;
bool sim(int l) {
	int cnt = 0;
	for (int i = 0; i < K; ++i) cnt += len[i] / l;
	return cnt >= N;
}
int main() {
	int i;
	for (scanf("%d%d", &K, &N), i = 0; i < K; ++i) scanf("%d",len+i);
	long long l = 1;
	long long r = (1<<31)-1;
	while (l <= r) {
		long long m = (l + r) >> 1;
		if (sim(m)) l = m + 1;
		else r = m - 1;
	}
	printf("%d",l-1);
}