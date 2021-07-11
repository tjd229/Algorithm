//greedy
#include <stdio.h>
#include <algorithm>
#include <vector>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
int main() {
	int i, n;
	vector<pll > v;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		ll a, b; scanf("%I64d%I64d",&a,&b);
		v.push_back({b,a});
	}
	sort(v.begin(), v.end());
	ll cost = 0;
	ll buy = 0;
	int l = 0, r = n - 1;
	while (l < r) {
		while (l < r && buy < v[l].first) {
			if (buy + v[r].second > v[l].first) {
				ll d = v[l].first - buy;
				v[r].second -=d;
				buy += d;
				cost += d + d;
			}
			else {
				ll d = v[r].second;
				buy += d; cost += d + d;
				r--;
			}
		}
		if (l == r) break;
		ll d = v[l].second;
		buy += d; cost += d;
		++l;
	}
	if (buy >= v[l].first) cost += v[l].second;
	else if (buy + v[l].second > v[l].first) {
		ll d = v[l].first-buy;
		cost += d + d; 
		d = v[l].second - d;
		cost += d;
	}
	else cost += (v[l].second << 1);
	printf("%I64d",cost);
	return 0;
}