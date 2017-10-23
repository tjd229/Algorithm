//category : string, lcp

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int g[10002];
int s_ix[10001];
int tmp[10001];
int d;
bool cmp(int a, int b){
	if (g[a] != g[b]) return g[a] < g[b];
	return g[a + d] < g[b + d];
}
int main(){
	int i,j;
	int bound;
	int ans = 0;
	int lcp;
	string s1, s2;
	cin >> s1 >> s2;
	bound = s1.size();
	s1 += 'x'+s2;
	
	for (i = 0; i < s1.size(); i++){
		s_ix[i] = i;
		g[i] = s1[i];
	}
	g[i] = -1;
	d = 1;
	do{
		sort(s_ix, s_ix + s1.size(), cmp);
		tmp[s_ix[0]] = 0;
		for (i = 1; i < s1.size(); i++)
			tmp[s_ix[i]] = tmp[s_ix[i - 1]] + cmp(s_ix[i - 1], s_ix[i]);
		for (i = 0; i < s1.size(); i++)
			g[i] = tmp[i];
		d <<= 1;
	} while (g[s_ix[s1.size()-1]]!=s1.size()-1);
	d = 0;
	for (i = 0; i < s1.size(); i++){
		if (g[i] == 0) continue;
		j = s_ix[g[i] - 1];
		d = max(d - 1, 0);
		lcp = 0;
		while (i + d < s1.size() && j + d < s1.size() && s1[i + d] == s1[j + d]){
			lcp = ++d;
		}
		d = lcp - 1;
		if ((i >= bound) ^ (j >= bound)) ans = max(ans, lcp);

	}
	cout << ans;

	return 0;
}