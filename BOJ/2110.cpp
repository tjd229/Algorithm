//bs
#include <stdio.h>
#include <algorithm>
using namespace std;
int N, C;
int pos[200000];
bool sim(int d) {
	int cnt = 1;
	int last = pos[0];
	for (int i = 1; i < N; ++i) {
		if (pos[i] - last >= d) {
			last = pos[i];
			++cnt;
		}
	}
	return cnt >= C;
}
int main() {
	int i;
	for (scanf("%d%d", &N, &C), i = 0; i < N; ++i) scanf("%d",pos+i);
	sort(pos, pos + N);
	int l = 1;
	int r = 1e9;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (sim(m)) l = m + 1;
		else r = m - 1;
	}
	int ans = l - 1;
	
	printf("%d",l-1);
}