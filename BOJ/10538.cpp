//category : hashing

#include <iostream>
#include <string>
using namespace std;
//const int mod1 = 1000000007;
const int mod = 1000000007;
long long h[2000][2000];
string mp[2000];
long long subtract(long long a,long long b){
	if (b >= mod) b %= mod;
	if (a < b) a += mod;
	a -= b;
	if (a >= mod) a %= mod;
	return a;
}
int main(){
	int i, j;
	int hp, wp, hm, wm;
	int e = 3;
	int ans = 0;
	long long m;
	long long p = 0;
	long long eh, ew;
	eh = ew = 1;
	string s;
	cin >> hp >> wp >> hm >> wm;
	for (i = 0; i < hp; i++){
		cin >> s;
		for (j = 0; j < wp; j++){
			p *= e;
			if (p >= mod) p %= mod;
			p += (s[j] == 'o')+1;
			if (p >= mod) p %= mod;
		}

	}
	for (j = 1; j < wp; j++){
		ew *= e;
		if (ew >= mod) ew %= mod;
	}
	
	for (i = 1; i < hp; i++){
		eh *= ew*e;
		if (eh >= mod) eh %= mod;
	}

	for (i = 0; i < hm; i++){
		cin >> mp[i];
	}
	for (j = 0; j < wm; j++){
		for (i = 0; i < hp; i++){
			h[0][j] *= ew*e;
			if (h[0][j] >= mod) h[0][j] %= mod;
			h[0][j] += (mp[i][j]=='o')+1;
			if (h[0][j] >= mod) h[0][j] %= mod;
		}
		for (; i < hm; i++){
			h[i - hp + 1][j] = h[i - hp][j];
			h[i - hp + 1][j] = subtract(h[i - hp + 1][j],((mp[i-hp][j]=='o')+1)*eh);
			h[i - hp + 1][j] *= ew*e;
			if (h[i - hp + 1][j] >= mod) h[i - hp + 1][j] %= mod;
			h[i - hp + 1][j] += (mp[i][j] == 'o') + 1;
			if (h[i - hp + 1][j] >= mod) h[i - hp + 1][j] %= mod;
		}
	}
	for (i = 0; i <= hm - hp; i++){
		m = 0;
		for (j = 0; j < wp; j++){
			m *= e;
			if (m >= mod) m %= mod;
			m += h[i][j];
			if (m >= mod) m%mod;
		}
		ans += (m == p);
		for (; j < wm; j++){
			m = subtract(m,h[i][j-wp]*ew);
			m *= e;
			if (m >= mod) m %= mod;
			m += h[i][j];
			if (m >= mod) m%mod;
			ans += (m == p);
			
		}


	}
	cout << ans;
	return 0;

}