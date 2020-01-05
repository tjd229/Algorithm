//line sweeping, greedy
#include <stdio.h>
#include <algorithm>
#define ll long long 
#define pii pair<int,int>
using namespace std;
pii prob[200002];
int opt(int t,int a,int b,int ne,int nh) {
	if (t < 0) return 0;
	int sole = t / a;
	if (sole > ne) sole = ne;
	t -= sole * a;
	int solh = t / b;
	if (solh > nh) solh = nh;
	return sole + solh;
}
int main() {
	int i, m;
	for (scanf("%d", &m); m--;) {
		int n, T, a, b;
		int nh = 0;
		for (scanf("%d%d%d%d", &n, &T, &a, &b), i = 1; i <= n; ++i)
			scanf("%d", &prob[i].second), nh += prob[i].second;
		for (i = 1; i <= n; ++i) scanf("%d", &prob[i].first);
		sort(prob + 1, prob + 1 + n);
		prob[n + 1] = { T + 1,0 };
		int ne = n - nh;
		int ans = opt(prob[1].first-1,a,b,ne,nh);
		ll s = 0;
		int cnt = 0;
		for (i = 1; i <= n;) {
			int t = prob[i].first;
			while (i <= n && prob[i].first == t) {
				if (prob[i].second) s += b, --nh;
				else s += a, --ne;
				++i; ++cnt;
			}
			if (s < prob[i].first) {
				int r = prob[i].first - s - 1;//--r
				int star = opt(r,a,b,ne,nh);
				if (ans < cnt + star) ans = cnt + star;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}