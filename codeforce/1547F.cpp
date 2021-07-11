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
int gcd(int a, int b) {
	if (a > b) a ^= b ^= a ^= b;
	if (a == 0) return b;//a<b
	return gcd(b%a, a);
}
void facto(int x, vector<int> &v) {
	for (int i = 2; i*i <= x; ++i) {
		if (x%i == 0) {
			v.push_back(i);
			while (x %i==0) x /= i;
		}
	}
	if (x > 1) v.push_back(x);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, j,n; cin >> n;
		vector<int> A,AA;
		for (i = 1; i <= n; ++i) {
			int a; cin >> a;
			A.push_back(a);
		}
		int d = A[0];
		for (i = 1; i < A.size(); ++i)
			d = gcd(d, A[i]);
		for (i = 0; i < n; ++i) A[i] /= d;
		AA = A;
		for (auto x : A) AA.push_back(x);
		int ans = 0;
		for (i = 0; i < n;++i) {
			int d = AA[i];
			if (d > 1) {
				vector<int> v; facto(AA[i], v);
				for (auto p : v) {
					int l = i, r = i;
					for (; l - 1 >= 0; ++l) {
						if (AA[l-1] % p) break;
					}
					for (; r + 1 < i + n; ++r) {
						if (AA[1 + r] % p) break;
					}
					int len = r - l + 1;
					if (ans < len) ans = len;
					while (l <= r) {
						while (AA[l] % p == 0) 
							AA[l] /= p;
						
						++l;
					}
				}
			}
		}
		cout << ans << "\n";
	}
 
	return 0;
}