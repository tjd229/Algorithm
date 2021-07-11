//greedy
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
ll a[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,n; ll k, x;
	vector<pll > g;
	vector<ll > d;
	cin >> n >> k >> x;
	for (i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (i = 1; i <= n;) {
		int l = i;
		int r = l+1;
		while (r <= n && a[r] - a[r-1] <= x) ++r;
		g.push_back({a[l],a[r-1]});
		//printf("%lld,%lld\n",a[l],a[r-1]);
		i = r;
	}
	int num = g.size();
	//cout << num << endl;
	if (num == 1) cout << num;
	else {
		for (i = 1; i < g.size(); ++i) {
			d.push_back(g[i].first-g[i-1].second);
		}
		sort(d.begin(), d.end());
		for (i = 0; i < d.size() && k>0; ++i) {
			ll div = d[i] / x - 1;
			int r = (d[i] % x) > 0;
			ll req = div + r;
			if (k >= req) {
				--num;
			}
			k -= req;
		}
		cout << num;
	}
	
 
	return 0;
}