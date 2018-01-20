//category : math, string

#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
const int bnd = 1e6;
ll facto[bnd + 1];
ll inv[bnd + 1];
ll invf[bnd + 1];
ll p(ll n,int e){
	ll res = 1;
	while (e != 0){
		if (e & 1){
			res *= n;
			res %= mod;
		}
		e >>= 1;
		n = n*n%mod;
	}
	return res;
}
ll nCk(ll n, ll k){
	ll nu = facto[n];
	ll de = invf[k] * invf[n - k]%mod;
	return nu*de%mod;
}
ll cnt_less(ll tot, vector<int> cnt, vector<int> r, const string &s){
	int i, j;
	ll res = 0;
	ll tmp;
	int last = -1;
	for (i = 0; i < s.size(); i++){
		tmp = 0;
		last = -1;
		for (j = 0; j < 26; j++){
			
			if (cnt[j] == 0||j>s[i]-'a') continue;
			//if (r[j] == 1) break;

			tot = tot*cnt[j] % mod;
			tot = tot*inv[r[j]] % mod;
			cnt[j]--;
			r[j]--;
			if (last != -1){
				cnt[last]++;
				tot = tot*(r[last]+1-cnt[last]) % mod;
				tot = tot*inv[cnt[last]] % mod;
			}
			last = j;
			if (j == s[i] - 'a') break;

			res += tot;
		}
		if (last!=s[i]-'a') break;
	}
	return res;
}
int main(){
	int i;
	vector<int> cnt(26);
	vector<int> r(26);
	string a, b;
	ll tot=1;
	for (inv[0]=invf[0]=facto[0]= i = 1; i <= bnd; i++){
		facto[i] = facto[i - 1] * i%mod;
		invf[i] = p(facto[i], mod - 2);
		inv[i] = p(i,mod-2);
	}
	cin >> a >> b;	
	for (i = 0; i < a.size(); i++)
		cnt[a[i] - 'a']++;
	for (i = 1, r[0] = a.size(); i < 26; i++)
		r[i] = r[i - 1] - cnt[i - 1];
	for (i = 0; i < 26; i++)
		tot = tot*nCk(r[i],cnt[i])%mod;
	ll ans = cnt_less(tot, cnt, r, b) - cnt_less(tot, cnt, r, a)-1;
	while (ans < 0) ans += mod;
	cout << ans%mod;

	return 0;
}
