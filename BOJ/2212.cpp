//greedy

#include <stdio.h>
#include <algorithm>
using namespace std;
int pos[10000];
int d[10000];
int main() {
	int i;
	int N, K;
	int ans = 0;
	for (scanf("%d%d", &N, &K), i = 0; i < N; ++i) scanf("%d",pos+i);
	sort(pos, pos + N);
	int n = unique(pos,pos+N)-pos;
	if (n > K) {
		for (i = 1; i < n; ++i) d[i] = pos[i] - pos[i - 1];
		sort(d + 1, d + n);
		for (i = 1; n>K; ++i,--n) ans += d[i];
	}
	printf("%d",ans);
	return 0;
}
