//category : string, lcp

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int d,k;
int g[19][100001];
int s_ix[100000];
string S;
bool cmp(int a, int b){
	if (g[k][a] != g[k][b]) return g[k][a] < g[k][b];
	return g[k][a + d] < g[k][b + d];
}

int get_lcp(int a,int b,int _d,int _k){
	if (a == b&&_k == k) return S.size()-s_ix[g[k][a]];
	int lcp = 0;
	while (_k != 0 && g[_k][a] != g[_k][b]){
		_k--;
		_d >>= 1;
	}
	
	if (g[_k][a] == g[_k][b])
		lcp += _d + get_lcp(a + _d, b + _d, _d, _k);
	return lcp;
}
int main(){
	int i, j;
	int l, r, m;
	vector<int> v;
	cin >> S;
	for (i = 0; i < S.size(); i++){
		s_ix[i] = i;
		g[0][i] = S[i];
	}
	g[0][i] = -1;
	d = 1;
	do{
		sort(s_ix, s_ix + S.size(), cmp);
		g[k+1][s_ix[0]] = 0;
		for (i = 1; i < S.size(); i++)
			g[k+1][s_ix[i]] = g[k+1][s_ix[i - 1]] + cmp(s_ix[i - 1], s_ix[i]);
		g[k + 1][i] = -1;
		d <<= 1;
		k++;
	} while (g[k][s_ix[S.size() - 1]] != S.size() - 1);
	//d = 0;

	for (i = S.size()-1; i >0; i--){
		if (get_lcp(0, i,d,k) == S.size() - i)
			v.push_back(S.size() - i);
		//cout << get_lcp(0,i,d,k) << endl;
	}

	cout << v.size() + 1 << "\n";

	for (i = 0; i <v.size(); i++){
		j = S.size() - v[i];
		l = g[k][j];
		r = S.size() - 1;
		while (l <= r){
			m = (l + r) >> 1;
			if (get_lcp(j,s_ix[m],d,k) >= v[i])
				l = m + 1;
			else r = m - 1;
		}
		cout << v[i] << " " << l - g[k][j] << "\n";
	}
	cout << S.size() << " " << 1;
	

	return 0;
}