//category : string, hashing

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#define ll long long
#define mp make_pair
#define pll pair<ll,ll>
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = mod1 + 2;
const int e = 27;
ll game1[(int)1e6];
ll game2[(int)1e6];
ll e_pow1, e_pow2;
map<pll, int > m;
ll roll(ll h,int e,int val,int mod){
	h *= e;
	if (h >= mod) h %= mod;
	h += val;
	if (h >= mod) h %= mod;
	return h;
}
ll subtract(ll a,ll b, int mod){
	if (b >= mod) b %= mod;
	if (a < b) a += mod;
	a -= b;
	if (a >= mod) a %= mod;
	return a;
}
int main(){
	int i,j;
	int n, k,g;
	int nk;
	int curr=0;
	string circle,s;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> circle >> g;
	e_pow1 = e_pow2 = 1;
	for (i = 0; i < k; i++){
		e_pow1 = roll(e_pow1, e, 0, mod1);
		e_pow2 = roll(e_pow2, e, 0, mod2);
		game1[0] = roll(game1[0], e, circle[i] - 'a' + 1, mod1);
		game2[0] = roll(game2[0], e, circle[i] - 'a' + 1, mod2);
	}
	nk = n*k;
	for (i = 1,j=k; i < nk; i++,j++){
		if (j >= nk) j -= nk;
		game1[i] = roll(game1[i - 1], e, circle[j] - 'a' + 1, mod1);
		game1[i] = subtract(game1[i], e_pow1*(circle[i - 1]-'a'+1), mod1);
		game2[i] = roll(game2[i - 1], e, circle[j] - 'a' + 1, mod2);
		game2[i] = subtract(game2[i], e_pow2*(circle[i - 1]-'a'+1), mod2);
		//cout << game1[i] << "," << game2[i] << endl;
		
	}
	for (i = 0; i < g; i++){
		cin >> s;
		ll h1 = 0;
		ll h2 = 0;
		for (j = 0; j < k; j++){
			h1 = roll(h1, e, s[j] - 'a' + 1, mod1);
			h2 = roll(h2, e, s[j] - 'a' + 1, mod2);
		}
		m.insert(mp(mp(h1,h2),i+1));
		//cout << h1 << "," << h2 << endl;
	}
	
	for (i = 0; i < k; i++){
		vector<int> v;
		set<ll> st1, st2;		
		for (j = 0,curr=i; j < n; j++,curr+=k){
			if (curr >= nk) curr -= nk;
			if (st1.find(game1[curr]) != st1.end() && st2.find(game2[curr]) != st2.end())
				break;
			if (m.find(mp(game1[curr],game2[curr])) != m.end()){
				v.push_back(m[mp(game1[curr], game2[curr])]);
				//cout << game1[curr] << "," << game2[curr] << endl;
			}
			else break;
			st1.insert(game1[curr]);
			st2.insert(game2[curr]);
		}
		if (v.size() == n){
			cout << "YES\n";
			for (i = 0; i < n; i++) cout << v[i] << " ";
			return 0;
		}
		//cout << v.size() << endl;
	}
	cout << "NO";
	


	return 0;
}
