//math, st, line sweeping, greedy
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
const int LEAF = 1 << 18;
const int mod = 1e9 + 7;
int st[LEAF + LEAF];
int a[300001];
int f[200001];
 
int gcd(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	if (a == mod || b == mod) return 1;
	if (a > b) a ^= b ^= a ^= b;
	if (a == 0) return b;//a<b
	return gcd(b%a, a);
}
void upd(int ix, int val) {
	st[ix] = val;
	ix >>= 1;
	while (ix > 0) {
		st[ix] = gcd(st[ix + ix + 1], st[ix + ix]);
		ix >>= 1;
	}
}
int rd(int ix, int s, int e, int from, int to) {
	if (from > to) return 0;
	if (e < from || to < s) return 0;
	if (from <= s && e <= to) return st[ix];
	int m = (s + e) >> 1;
	return gcd(rd(ix + ix, s, m, from, to), rd(ix + ix + 1, m + 1, e, from, to));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; t = 1;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) {
			cin >> a[i]; f[i] = 0;
 
		}
		int last = 1;
		if (a[1] == 1) {
			a[1] = mod;
			f[1] = 1;
			last = 2;
		}
		upd(LEAF + 1, a[1]);
		for (i = 2; i <= n; ++i) {
			if (a[i] == 1) {
				a[i] = mod;
				f[i] = 1;
				last = 1 + i;
			}
			else {
				int len = 1, d = a[i];
				while (last < i) {
					d = rd(1, 0, LEAF - 1, last, i-1);
					d = gcd(d, a[i]);
					len = i - last + 1;
					if (len <= d) break;
					++last;
				}
				if (len == d) {
					a[i] = mod;
					f[i] = 1;
					last = 1 + i;
				}
				
			}
			upd(LEAF + i, a[i]);
		}
		for (i = 1; i <= n; ++i) f[i] += f[i - 1], cout << f[i] << " ";
		cout << "\n";
		//init(1, 0, LEAF - 1, 0, n - 1);
	}
 
 
	return 0;
}