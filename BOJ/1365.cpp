//implementation
#include <stdio.h>
#include <algorithm>
using namespace std;
int d[100000];
int main() {
	int i, N;
	int ct = 0;
	for (scanf("%d", &N), i = 0; i < N; ++i) {
		int m; scanf("%d",&m);
		auto it = lower_bound(d, d + ct, m);
		*it = m;
		ct = max(ct, int(it - d + 1));
	}
	printf("%d",N-ct);
	return 0;
}