//line sweeping
#include <stdio.h>
#include <algorithm>
#include <vector>
#define ll long long
#define pii pair<int,int>
using namespace std;
int pop[100001];
int a[100001], b[100001];
pii ai[100001], bi[100001];
ll s[100001];
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n, m;
		for (scanf("%d%d", &n, &m), i = 1; i <= m; ++i) {
			scanf("%d%d", a + i, b + i);
			ai[i] = { a[i],i }; bi[i] = { b[i],i };
		}
		sort(ai+1, ai+1+m); sort(bi+1, bi+1+m);
		for (i = 1; i <= m; ++i) s[i] = s[i - 1] + ai[i].first;
		
		int it = 1;
		ll ans = -1;
		for (i = 1; i <= m; ++i) {
			while (it <= m && ai[it].first <= bi[i].first) {
				pop[ai[it].second] = t + 1;
				++it;
			}
			ll h = 0;
			int num = m - (it - 1);
			if (num > n) h = s[m] - s[m - n];
			else {
				
				ll r = n - num;
				h = s[m] - s[it - 1];//#:m-(it-1)
				if (pop[bi[i].second] == t + 1) {
					--r;
					h += a[bi[i].second];
				}
				if (r < 0) h = -1e9;
				else h += bi[i].first * r;
				//printf("r:%lld*%d\n",r,bi[i].first);
			}
			//printf("%d:%lld\n",bi[i].second,h);
			if (ans < h) ans = h;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}