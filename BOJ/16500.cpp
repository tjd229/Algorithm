//hashing, dp

#include <iostream>
#include <string>
#define ll long long
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int base = 26;
int match[100][100];
int len[100];
int d[100];
ll h1[100], h2[100];
ll pbase1[100], pbase2[100];
string S;
ll roll(ll h, int val, int mod) {
	h = h * base%mod;
	return (h + val) % mod;
}
ll get_hash(int s,int e,int mod,ll *h, ll *base) {
	if (s == 0) return h[e];
	ll res = h[e] - h[s - 1] * base[e - s] % mod;
	while (res < 0) res += mod;
	return res;
}
void matching(string &T,int *arr) {
	if (S.size() < T.size()) return;
	ll th1, th2;
	th1 = th2 = 0;
	for (auto c : T) {
		th1=roll(th1, c - 'a', mod1);
		th2=roll(th2, c - 'a', mod2);
	}
	for (int i = T.size() - 1; i < S.size(); ++i) {
		arr[i] = get_hash(i-T.size()+1,i,mod1,h1,pbase1)==th1
			&& get_hash(i - T.size() + 1, i, mod2, h2, pbase2) == th2;
		
	}
	//printf("%lld,%lld\n%lld,%lld\n", get_hash(1, 8, mod1, h1, pbase1), get_hash(1, 8, mod2, h2, pbase2), th1,th2);

}
int main() {
	int i, N;
	cin >> S >> N;
	pbase1[0] = pbase2[0] = base;
	h1[0] = h2[0] = S[0] - 'a';
	for (i =1; i < S.size(); ++i) {
		h1[i] = roll(h1[i-1], S[i] - 'a', mod1);
		h2[i] = roll(h2[i - 1], S[i] - 'a', mod2);
		pbase1[i] = roll(pbase1[i - 1], 0, mod1);
		pbase2[i] = roll(pbase2[i - 1], 0, mod2);
	}
	for (i = 0; i < N; ++i) {
		string T;
		cin >> T;
		len[i] = T.size();
		matching(T, match[i]);
	}
	for (i = 0; i < S.size(); ++i) {
		for (int j = 0; j < N && !d[i]; ++j) {
			if (i == len[j] - 1) d[i] |= match[j][i];
			else if (i >= len[j]) d[i] |= (match[j][i] & d[i-len[j]]);
		}
	}
	cout << d[S.size() - 1];
	return 0;
}
