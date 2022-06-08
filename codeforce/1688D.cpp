//math, greedy
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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, k; cin >> n >> k;
		for (i = 1; i <= n; ++i) cin >> a[i];
		ll ans = 0;
		if (n == 1) {
			ans = a[1];
			ans += k - 1;
		}
		else if(n==k){
			for (i = 1; i <= n; ++i) ans += a[i]+i-1;
 
		}
		else if (n > k) {
			ll base = 0;
			for (i = 1; i <= k; ++i) base += i+a[i]-1;
			ans = max(ans, base);
			for (i = k + 1; i <= n; ++i) {
				base -= a[i - k];
				base += a[i];
				ans = max(ans, base);
			}
		}
		else {//n<k
			for (i = 1; i <= n; ++i)ans += a[i];
			int r = k - n;
			int d = r / (n - 1);
			int rem = r % (n - 1);
			ll perm_len = n - 1;
			ll s = 2, e = perm_len * 2;
			ll base= (s + e)*perm_len / 2;
			ans += base * d;
			if (rem == 0) {
				for (i = 0; i < n; ++i) ans += i;
			}
			else {
				int tot = rem + n;
				vector<ll> head;
				for (i = 0; i <= rem; ++i) head.push_back(i);
				int sz = head.size() - 1;//min sz is 1
				ll base = 2;
				for (i = 0; i < sz; ++i) {
					head.push_back(base);
					base += 2;
				}
				for (i = head.size(); i < tot; ++i) {
					int _len = head.size();
					head.push_back(_len);
					//printf("~%d\n",_len);
				}
				/*for (auto x : head) {
					printf("%lld\n",x);
				}*/
				for (auto x : head) ans += x;
				
 
			}
 
		}
		cout << ans << "\n";
 
	}
 
 
	return 0;
}