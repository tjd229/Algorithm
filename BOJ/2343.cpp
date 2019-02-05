//bs
#include <stdio.h>
#define ll long long
int len[100000];
int N, M;
bool sim(int bnd) {
	int cnt = 1;
	ll tot = 0;
	for (int i = 0; i < N; ++i) {
		if (bnd < len[i]) return 0;
		if (tot + len[i] > bnd) {
			tot = 0;
			++cnt;
		}
		tot += len[i];
	}
	return M >= cnt;
}
int main() {
	int i;
	int l = 1;
	int r = 1e9;
	for (scanf("%d%d", &N, &M), i = 0; i < N; ++i) scanf("%d",len+i);

	while (l <= r) {
		int m = (l + r) >> 1;
		if (sim(m)) r = m - 1;
		else l = m + 1;
	}
	printf("%d",r+1);
	return 0;
}