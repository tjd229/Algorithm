//category : string, hashing

#include <iostream>
#include <string>
#include <map>
#include <vector>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = mod1 + 2;
const int base = 26;

ll roll(ll h,int val,int mod){
	h *= base;
	h %= mod;
	h += val;
	return h%mod;
}
ll subtract(ll a,ll b,ll mod){
	ll h = a - b;
	while (h < 0) h += mod;
	return h %= mod;
}
int main(){
	int i,j,c;
	int _S, _T;
	bool check = 0;
	vector<int> ans;
	string S, T;
	cin >> _S >> _T >> S >> T;
	map<pll,int > m;
	ll l1 = 1;
	ll l2 = 1;
	ll ht1[base] = { 0 };
	ll ht2[base] = { 0 };
	ll hs1[base] = { 0 };
	ll hs2[base] = { 0 };
	for (i = 0; i < _T; i++){
		for (j = 0; j < base; j++){
			ht1[j] = roll(ht1[j], T[i] == ('a' + j), mod1);
			ht2[j] = roll(ht2[j], T[i] == ('a' + j), mod2);
			hs1[j] = roll(hs1[j], S[i] == ('a' + j), mod1);
			hs2[j] = roll(hs2[j], S[i] == ('a' + j), mod2);
		}
		if (i == 0) continue;
		l1 = roll(l1, 0, mod1);
		l2 = roll(l2, 0, mod2);
	}
	for (i = 0; i < base; i++){
		if (ht1[i] + ht2[i]) m[{ht1[i], ht2[i]}] = i;
	}
	for (i = 0, c = _S - _T ; i <= c; i++){
		check = true;
		
		for(j = 0; i&&j < base; j++){
			hs1[j] = roll(hs1[j], S[i+_T-1] == ('a' + j), mod1);
			hs2[j] = roll(hs2[j], S[i+_T-1] == ('a' + j), mod2);
		}
		for (j = 0; check&&j < base; j++){
			if (hs1[j] + hs2[j] == 0) continue;
			if (m.find({ hs1[j], hs2[j] }) != m.end()){
				int ix = m[{hs1[j], hs2[j]}];
				check &= ((hs1[ix] == ht1[j]) && (hs2[ix] == ht2[j]));
			}
			else check = false;
		}
		if (check) ans.push_back(i+1);
		hs1[S[i] - 'a'] = subtract(hs1[S[i] - 'a'], l1, mod1);
		hs2[S[i] - 'a'] = subtract(hs2[S[i] - 'a'], l2, mod2);
	}
	cout << ans.size() << "\n";
	for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";

	return 0;
}
