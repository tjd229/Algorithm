//greedy

#include <stdio.h>
#include <algorithm>
#define pii pair<int,int>
#define ll long long
using namespace std;
pii stop[100001];
int main() {
	int i;
	int L, N, rf, rb;
	ll ans = 0;
	for (scanf("%d%d%d%d", &L, &N, &rf, &rb), i = 1; i <= N; ++i) {
		int x, c;
		scanf("%d%d", &x,&c);
		stop[i] = {-c,-x};
	}
	sort(stop + 1, stop + 1 + N);
	int last = 0;
	int delay = rf - rb;
	for (i = 1; i <= N; ++i) {
		if (last < -stop[i].second) {
			ll d = -stop[i].second - last;
			ans += d*delay*-stop[i].first;
			last = -stop[i].second;
		}
	}
	printf("%lld",ans);
	return 0;
}
