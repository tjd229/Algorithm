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
int a[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll X; cin >> X;
	vector<ll> v;
	ll _X = X;
	for (ll i = 2; i*i <= _X; ++i) {
		if (_X%i == 0) {
			ll val = 1;
			while (_X%i == 0) {
				val *= i;
				_X /= i;
			}
			v.push_back(val);
		}
	}
	if (_X > 1) v.push_back(_X);
	if (_X == X) {
		cout << 1 << " " << X;
		return 0;
	}
	/*for (auto x : v)
		cout << x << endl;*/
	int sz = v.size();
	int bnd = (1 << sz);
	ll ans1, ans2, mx = X+1;
	for (int i = 0; i < bnd; ++i) {
		ll a = 1, b = 1;
		for (int j = 0; j < sz; ++j) {
			if (i&(1 << j)) a *= v[j];
			else b *= v[j];
		}
		ll _mx = a < b ? b : a;
		if (mx > _mx) {
			mx = _mx;
			ans1 = a; ans2 = b;
		}
	}
	cout << ans1 << " " << ans2;
	return 0;
}