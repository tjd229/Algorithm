//implementation
#include <iostream>
#include <string>
using namespace std;
int sum[2][1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, q, n;
		string s; cin >> s >> q;
		n = s.size();
		for (i = 0; i < n; ++i) {
			if (s[i] == '[' || s[i] == ']')
				sum[1 - (i & 1)][1+i] = 1;
			else sum[1 - (i & 1)][1+i] = 0;
			sum[i & 1][1 + i] = 0;
		}
		for (i = 1; i <= n; ++i) {
			sum[0][i] += sum[0][i - 1];
			sum[1][i] += sum[1][i - 1];
		}
		while(q--) {
			int l, r; cin >> l >> r;
			int ans = (sum[0][r] - sum[0][l - 1]);
			ans-= (sum[1][r] - sum[1][l - 1]);
			if (ans < 0) ans = -ans;
			cout << ans << "\n";
		}
		
	}
 
	return 0;
}