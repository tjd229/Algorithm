//math

 #include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int d[100];
int d_[100];
ll pow(ll b,int e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res *= b;
		}
		b = b * b;
		e >>= 1;
	}
	return res;
}
ll calc(ll n) {
	ll res = 1;
	while (n) {
		res *= n % 10;
		n /= 10;
	}
	return res;
}
int main() {
	ll n;
	cin >> n;
	int b = 0;
	ll nine = 0; ll _n = n;
	ll base = 1;
	ll ans = -1;
	ans = calc(n);
	while (_n) {
		d[b++] = _n % 10;
		_n /= 10;
		nine *= 10; nine += 9;
		base *= 10;
		ans = max(ans, calc(base*(_n - 1) + nine));
	}
	cout << ans;
	//cout << b;
	
	return 0;
}
