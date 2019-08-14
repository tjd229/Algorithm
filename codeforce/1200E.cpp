//string, hashing
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
const int mod1 = 1e9 + 7;
const int mod2 = mod1 + 2;
string word[100000];
string ans;
ll lh1, lh2, rh1, rh2;
 
ll roll(ll h, ll val,ll base, ll mod) {
	h = h * base%mod;
	h += val;
	return h % mod;
}
void merge(int ix) {
	lh1 = lh2 = rh1 = rh2 = 0;
	int len = -1;
	int l = ans.size() - 1;
	int r = 0;
	int base = 256;
	ll b1, b2;
	b1 = b2 = 1;
	while (l >= 0 && r < word[ix].size()) {
		lh1=roll(lh1, ans[l]*b1%mod1,1, mod1);
		lh2=roll(lh2, ans[l]*b2%mod2,1, mod2);
		rh1=roll(rh1, word[ix][r],256, mod1);
		rh2=roll(rh2, word[ix][r],256, mod2);
		
		if (lh1 == rh1 && rh2 == lh2) len = r;
		b1 = b1 * 256 % mod1;
		b2 = b2 * 256 % mod2;
		--l; ++r;
	}
	//cout << len << endl;
	
	for (++len; len < word[ix].size(); ++len)
		ans += word[ix][len];
	//cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> word[i];
	ans = word[0];
	for (int i = 1; i < n; ++i) {
		merge(i);
		//break;
	}
	cout << ans;
	return 0;
}