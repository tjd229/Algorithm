//category : string, SA

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int g[5001];
int tmp[5000];
int s_ix[5000];
int d;
bool cmp(int a, int b){
	if (g[a] != g[b]) return g[a] < g[b];
	return g[a + d] < g[b + d];
}
int main(){
	int i, j;
	string s;
	int ans = 0;
	int lcp;
	cin >> s;
	for (i = 0; i < s.size(); i++){
		s_ix[i] = i;
		g[i] = s[i];
	}
	g[i] = -1;
	d = 1;
	do{
		sort(s_ix, s_ix + s.size(), cmp);
		tmp[s_ix[0]] = 0;
		for (i = 1; i < s.size(); i++)
			tmp[s_ix[i]] = tmp[s_ix[i - 1]] + cmp(s_ix[i - 1], s_ix[i]);
		for (i = 0; i < s.size(); i++)
			g[i] = tmp[i];
		d <<= 1;
	} while (g[s_ix[s.size() - 1]] != s.size() - 1);
	d = 0;
	for (i = 0; i < s.size(); i++){
		if (g[i] == 0) continue;
		j = s_ix[g[i] - 1];
		d = max(0, d - 1);
		lcp = 0;
		while (j + d < s.size() && i + d < s.size() && s[i + d] == s[j + d])
			lcp = ++d;
		d = lcp - 1;
		ans = max(lcp, ans);
	}
	cout << ans;
	return 0;
}
