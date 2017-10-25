//category : string, SA

#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;
int tmp[1000000];
int g[1000001];
int s_ix[1000000];
int d;
bool cmp(int a, int b){
	if (g[a] != g[b]) return g[a] < g[b];
	return g[a + d] < g[b + d];
}
int main(){
	int i, j;
	int lcp = 0;
	ll cnt = 0;
	ll total = 0;
	string S;
	cin >> S;
	for (i = 0; i < S.size(); i++){
		g[i] = S[i];
		s_ix[i] = i;
		total += (i + 1);
	}
	g[i] = -1;
	d = 1;
	do{
		sort(s_ix, s_ix + S.size(), cmp);
		tmp[s_ix[0]] = 0;
		for (i = 1; i < S.size(); i++)
			tmp[s_ix[i]] = tmp[s_ix[i-1]] + cmp(s_ix[i - 1], s_ix[i]);
		for (i = 0; i < S.size(); i++)
			g[i] = tmp[i];
		d <<= 1;

	} while (g[s_ix[S.size() - 1]] != S.size() - 1);
	d = 0;
	for (i = 0; i < S.size(); i++){
		if (g[i] == 0) continue;
		j = s_ix[g[i] - 1];
		d = max(0, d - 1);
		lcp = 0;
		while (i + d < S.size() && j + d < S.size() && S[i + d] == S[j + d])
			lcp = ++d;
		d = lcp - 1;
		cnt += lcp;
	}
	cout << total - cnt;


	return 0;
}
