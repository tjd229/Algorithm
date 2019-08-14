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
ll seg[3];
ll gcd(ll a, ll b) {
	if (a == 0) return b;
	return gcd(b%a,a);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << gcd(3,6);
	ll n, m; int q;
	cin >> n >> m >> q;
 
	ll d = 1;	
	if (n > m) d = gcd(m, n);
	else
		d = gcd(n, m);
	
	seg[1] = n / d;
	seg[2] = m / d;
	while (q--) {
		ll sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		--sy; --ey;
		if (sy / seg[sx] == ey / seg[ex]) cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}