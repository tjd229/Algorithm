//math
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
using namespace std;
int loop[1000000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i;
	ll k, l, r, t, x, y; cin >> k >> l >> r >> t >> x >> y;
	ll d = y - x;
	if (d == 0) {
		if (k - x<l && k + y>r) cout << "No\n";
		else cout << "Yes\n";
	}
	else if (d < 0) {
		if (k + y <= r) k += y;
		ll corner = l + x;
		ll delta = k - (corner-1);
		if (delta <= 0) {
			cout << "No";
			return 0;
		}
		ll save = delta / (-d)+((delta%(-d))>0);
		if (save >= t) cout << "Yes";
		else cout << "No";
	}
	else {
		if (k + y <= r) k += y;
		ll corner = l + x;
		ll delta = k - (corner-1);
		if (delta <= 0) {
			cout << "No";
			return 0;
		}
		ll save= delta / (x) + ((delta % (x)) > 0);
		t -= save; k -= save * x;
		if (t <= 0) {
			cout << "Yes";
			return 0;
		}
		r -= l; k -= l; l = 0;
		l -= x; r -= x; k -= x;
		corner = 0;
		bool inf = 0;
		//printf("%lld,%lld\n",l,r);
		//printf("%lld,%lld\n",k,t);
		while (t > 0) {
			k += y;
			//printf("%lld\n",k);
			if (k > r){
				cout << "No";
				return 0;
			}
			ll d = k / x;
			k -= d * x; t -= d;
			if (loop[k]) {
				inf = 1;
				break;
			}
			loop[k] = 1;
			k -= x; --t;
			//printf("%lld\n", k);
			if (k < l) {
				cout << "No";
				return 0;
			}
		}
		cout << "Yes";
	}
 
	return 0;
}