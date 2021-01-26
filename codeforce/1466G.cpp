//string, hashing
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = mod1 + 2;
int len[25];
string s,s0,t,w[100000];
int k[100000];
ll acnt[26][100001],pw[100001];
ll base1[1000001], base2[1000001];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n, q; cin >> n >> q >> s0 >> t;
	int mxw = 0;
	for (i = 0; i < q; ++i) {
		cin >> k[i] >> w[i];
		if (mxw < w[i].size()) mxw = w[i].size();
	}
	pw[0] = 1;
	for (i = 0; i < n; ++i) {
		pw[i + 1] = (pw[i] << 1) % mod1;
		for (int j = 0; j < 26; ++j) acnt[j][i + 1] = (acnt[j][i] << 1) % mod1;
		acnt[t[i] - 'a'][i + 1]= (acnt[t[i] - 'a'][i + 1]+1)%mod1;
	}
	
	base1[0] = base2[0] = 1;
	for (i = 1; i <= mxw; ++i) {
		base1[i] = (base1[i - 1] *26) % mod1;
		base2[i] = (base2[i - 1] *26) % mod2;
	}
 
	len[0] = s0.size(); s = s0;
	for (i = 0; i < n && len[i] < mxw; ++i) {
		s += t[i]+s;
		len[i+1] = s.size();
	}
	for (i = 0; i < q; ++i) {
		int base = 0;
		while (base<=k[i] && len[base] < w[i].size()) ++base;
		if (len[base] < w[i].size() || k[i]<base) {
			cout << "0\n";
			continue;
		}
		ll w1 = 0, w2 = 0, cnt = 0;
		ll h1 = 0, h2 = 0;
		int wsz = w[i].size();
		for (int j = 0; j < wsz;++j) {
			w1 = (w1 * 26 + w[i][j] - 'a') % mod1;
			w2 = (w2 * 26 + w[i][j] - 'a') % mod2;
			h1 = (h1 * 26 + s[j] - 'a') % mod1;
			h2 = (h2 * 26 + s[j] - 'a') % mod2;
		}
		ll lw1 = 0, lw2 = 0, rw1 = w1, rw2 = w2;
		vector<int> lh1 = { 0 }, lh2 = { 0 }, rh1 = {0}, rh2= {0};
		cnt= (h1 == w1) && (w2 == h2);
		for (int j = wsz; j < len[base]; ++j) {
			h1 = h1 * 26 - ((s[j - wsz]-'a') * base1[wsz]) % mod1;
			while (h1 < 0) h1 += mod1;
			h2 = h2 * 26 - ((s[j - wsz]-'a') * base2[wsz]) % mod2;
			while (h2 < 0) h2 += mod2;
			h1 = (h1 + s[j]-'a') % mod1; h2 = (h2 + s[j]-'a') % mod2;
			cnt += (h1 == w1) && (w2 == h2);
		}
		cnt = cnt * pw[k[i] - base] % mod1;
		for (int j = 1; j < wsz; ++j) {
			ll val = lh1.back();
			val = val + (s[len[base] - j] - 'a')*base1[j-1];
			lh1.push_back(val%mod1);
			val = lh2.back();
			val = val + (s[len[base] - j] - 'a')*base2[j-1];
			lh2.push_back(val%mod2);
			val = rh1.back(); val = val * 26 + s[j-1] - 'a';
			rh1.push_back(val%mod1);
			val = rh2.back(); val = val * 26 + s[j-1] - 'a';
			rh2.push_back(val%mod2);
		}
		reverse(rh1.begin(), rh1.end()); reverse(rh2.begin(), rh2.end());
		for (int j = 0; j < wsz; ++j) {
			
			rw1 = rw1 - ((w[i][j] - 'a') * base1[wsz - j - 1]) % mod1;
			while (rw1 < 0) rw1 += mod1;
			rw2 = rw2 - ((w[i][j] - 'a') * base2[wsz - j - 1]) % mod2;
			while (rw2 < 0) rw2 += mod2;
			rw1 %= mod1;rw2 %= mod2;
			if (lh1[j] == lw1 && lh2[j] == lw2 && rh1[j] == rw1 && rh2[j] == rw2) {
				cnt += acnt[w[i][j] - 'a'][k[i]] - (acnt[w[i][j] - 'a'][base] * pw[k[i] - base] % mod1);
				while (cnt < 0) cnt += mod1;
				cnt %= mod1;
			}
			lw1 = (lw1 * 26 + w[i][j] - 'a') % mod1; lw2 = (lw2 * 26 + w[i][j] - 'a') % mod2;
 
		}
		cout << cnt << "\n";
 
	}
	
	return 0;
}
