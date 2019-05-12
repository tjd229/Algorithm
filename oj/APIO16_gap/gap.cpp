#include "gap.h"
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
long long findGap(int T, int N)
{
	if (!N) return 0;
	vector<ll> a;
	ll res = 0;
	if (--T) {
		ll mn, mx,bnd;
		MinMax(0,1e18,&mn,&bnd);
		ll d = (bnd - mn)/(N-1);
		a.push_back(mn); a.push_back(bnd);
		ll l = mn, r = mn + d;
		res = d;
		for (;l< bnd;l+=d+1,r+=d+1) {
			MinMax(l, r, &mn, &mx);
			if (mn != -1) a.push_back(mn);
			if (mx != -1) a.push_back(mx);
		}
	}
	else {
		ll mn = -1, mx = (ll)1e18+1;
		for (int i = N; i > 0; i -= 2) {
			MinMax(mn + 1, mx - 1,&mn,&mx);
			a.push_back(mn); a.push_back(mx);
		}
	}
	sort(a.begin(), a.end());
	for (int i = 1; i < a.size(); ++i) {
		ll d = a[i] - a[i - 1];
		if (res < d) res = d;
	}
	return res;
}
