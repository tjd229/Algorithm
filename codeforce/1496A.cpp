//string
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, k; string s; cin >> n >> k >> s;
		int l = 0, r = n - 1;
		if (k == 0) {
			cout << "YES\n";
			continue;
		}
		while (l < r) {
			if (s[l] == s[r]) {
				++l; --r;
			}
			else break;
		}
		if (l == 0) {
			cout << "NO\n";
			continue;
		}
		if (l  > r) {
			++k;
		}
		if (l >= k)cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}