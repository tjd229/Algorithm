//category : string, hashing

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int mod = 10000000007;
int main(){
	string T, P;
	vector<int> ans;
	int i;
	int e = 257;
	long long t, p;
	long long pow_max = 1;
	long long d;
	getline(cin, T);
	getline(cin, P);
	//cin >> T >> P;
	//cout << T << endl;
	
	p = 0;
	for (i = 0; i < P.size(); i++){
		p *= e;
		if (p >= mod) p %= mod;
		p += (long long)(P[i] + 1);
		if (p >= mod) p %= mod;
		if (i > 0){
			pow_max *= e;
			if (pow_max >= mod) pow_max %= mod;
		}
	}
	t = 0;
	for (i = 0; i < P.size(); i++){
		t *= e;
		if (t >= mod) t %= mod;
		t += (long long)(T[i] + 1);
		if (t >= mod) t %= mod;
	}
	if (t == p) ans.push_back(0);
	for (i = P.size(); i < T.size(); i++){
	
		d = pow_max*(long long)(T[i-P.size()]+1);
		if (d >= mod) d %= mod;
		if (t < d) t += mod;
		t -= d;
		t *= e;
		if (t >= mod) t %= mod;
		t += (long long)(T[i] + 1);
		if (t >= mod) t %= mod;
		if (p == t) ans.push_back(i - P.size() + 1);
		
	}
	cout << ans.size()<<"\n";
	for (i = 0; i < ans.size(); i++) cout << ans[i]+1 << " ";

}

