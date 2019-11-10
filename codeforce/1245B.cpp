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
using namespace std;
int gcd(int a, int b) {
	if (a == 0) return b;//a<b
	return gcd(b%a,a);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, a, b, c;
	int n;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> a >> b >> c;
		string s; cin >> s;
		string ans = "";
		int win = 0;
		for (auto e : s) {
			if (e == 'R') {
				if (b) {
					--b;
					ans += 'P';
					++win;
				}
				else ans += '?';
			}
			else if (e == 'P') {
				if (c) {
					--c;
					ans += 'S';
					++win;
				}
				else ans += '?';
			}
			else {
				if (a) {
					--a;
					ans += 'R';
					++win;
				}
				else ans += '?';
			}
		}
		int bnd = (n >> 1) + (n & 1);
		if (win >= bnd) {
			for (int i = 0; i < n; ++i) {
				if (ans[i] == '?') {
					if (a) {
						--a;
						ans[i] = 'R';
					}
					else if (b) {
						--b;
						ans[i] = 'P';
					}
					else {
						--c;
						ans[i] = 'S';
					}
				}
			}
			cout << "YES\n" << ans << "\n";
		}
		else cout << "NO\n";
	}
 
	return 0;
}