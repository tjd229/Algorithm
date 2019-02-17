//string, hashing
#include <iostream>
#include <map>
#include <string>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
string mon[100001];
ll roll(ll h, int val, int base,int mod) {
	h = h * base%mod;
	return (h + val) % mod;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, N, M;
	map<pll, int> mp;
	cin >> N >> M;
	for (i = 1; i <= N; ++i) {
		cin >> mon[i];
		ll h1, h2;
		h1 = h2 = mon[i][0] - 'A';
		for (int j = 1; j < mon[i].size(); ++j) {
			h1 = roll(h1, mon[i][j] - 'a',26, mod1);
			h2 = roll(h2, mon[i][j] - 'a',26, mod2);
		}
		mp[{h1, h2}] = i;
	}
	while (M--) {
		string q;
		cin >> q;
		if (q[0] >= 'A' && q[0] <= 'Z') {
			ll h1, h2;
			h1 = h2 = q[0] - 'A';
			for (i = 1; i < q.size(); ++i) {
				h1 = roll(h1, q[i] - 'a',26, mod1);
				h2 = roll(h2, q[i] - 'a',26, mod2);
			}
			cout << mp[{h1, h2}]<<"\n";
		}
		else {
			int ix = 0;
			for (auto c : q) ix = roll(ix, c - '0', 10, mod1);
			cout << mon[ix]<<"\n";
		}
	}
	return 0;
}