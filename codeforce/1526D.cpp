//string
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
char i2c[4] = {'A','N','O','T'};
ll transform(vector<int> &perm,vector<int> &dna) {
	ll c = 0;
	int cnt[4] = { 0 };
	for (auto x : dna) ++cnt[x];
	for (auto x : dna) {
		for (int i = 0; i < 4; ++i) {
			if (perm[i] == x) break;
			c += cnt[perm[i]];
		}
		--cnt[x];
	}
	return c;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,t; cin >> t;
	while (t--) {
		vector<int> dna, perm = {0,1,2,3},ans;
		string a,b=""; cin >> a;
		ll mx = -1;
		for (auto c : a) {
			if (c == 'A') dna.push_back(0);
			else if (c == 'N') dna.push_back(1);
			else if (c == 'O') dna.push_back(2);
			else dna.push_back(3);
		}
		do {
			ll c = transform(perm, dna);
			if (mx < c) {
				mx = c;
				ans = perm;
			}
		} while (next_permutation(perm.begin(), perm.end()));
		int cnt[4] = { 0 };
		for (auto x : dna) ++cnt[x];
		for (auto k : ans) {
			while (cnt[k]--) b += i2c[k];
		}
		cout << b << "\n";
	}

	return 0;
}