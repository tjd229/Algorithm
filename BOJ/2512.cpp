//bs
#include <stdio.h>
#define ll long long
#define reg register
int req[10001];
int N,M;
bool sim(int bnd) {
	ll tot = 0;
	for (reg int i = 1; i <= N; ++i) {
		tot += req[i] > bnd ? bnd : req[i];
	}
	return tot <= M;
}
int main() {
	int i;
	int l = 1;
	int r = 0;
	for (scanf("%d", &N), i = 1; i <= N; ++i) {
		scanf("%d", req + i);
		if (req[i] > r) r = req[i];
	}
	scanf("%d",&M);
	while (l <= r) {
		int m = (l + r) >> 1;
		if (sim(m)) l = m + 1;
		else r = m - 1;
	}
	printf("%d",l-1);
	
	return 0;
}