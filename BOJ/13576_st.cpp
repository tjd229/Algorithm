//category : string, SA, st, bs

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int LEAF = 1 << 17;
int st[LEAF + LEAF];
int d;
int g[100001];
int lcp[100000];
int s_ix[100000];
bool cmp(int a, int b){
	if (g[a] != g[b]) return g[a] < g[b];
	return g[a + d] < g[b + d];
}
void update(int ix,int val){
	st[ix] = val;
	ix >>= 1;
	while (ix!=0){
		st[ix] = min(st[ix + ix], st[ix + ix + 1]);
		ix >>= 1;
	}
}
int get_min(int ix,int s,int e,int from,int to){
	if (to < from) return 0;
	if (e < from || to < s) return LEAF;
	if (from <= s&&e <= to) return st[ix];
	return min(get_min(ix + ix, s, (s + e) >> 1, from, to), get_min(ix + ix+1,1+( (s + e) >> 1),e, from, to));
}
int main(){
	int i, j;
	int l, r, m;
	string S;
	vector<int> v;
	cin >> S;
	for (i = 0; i < S.size(); i++){
		s_ix[i] = i;
		g[i] = S[i];
	}
	g[i] = -1;
	d = 1;
	do{
		sort(s_ix, s_ix + S.size(), cmp);
		lcp[s_ix[0]] = 0;
		for (i = 1; i < S.size(); i++)
			lcp[s_ix[i]] = lcp[s_ix[i - 1]] + cmp(s_ix[i-1],s_ix[i]);
		for (i = 0; i < S.size(); i++)
			g[i] = lcp[i];
		d <<= 1;
	} while (g[s_ix[S.size()-1]]!=S.size()-1);
	d = 0;
	lcp[0] = 0;
	for (i = 0; i < S.size(); i++){
		if (g[i] == 0) continue;
		j = s_ix[g[i] - 1];
		d = max(d - 1, 0);
		lcp[g[i]] = 0;
		while (i + d < S.size() && j + d < S.size() && S[i + d] == S[j + d])
			lcp[g[i]] = ++d;
		d = lcp[g[i]] - 1;
	}



	for (i = 0; i < S.size(); i++) update(LEAF + i, lcp[i]);

	for (i = 1; i < S.size(); i++){
		j = S.size() - i;
		if (get_min(1, 0, LEAF - 1, g[j] + 1, g[0]) + get_min(1, 0, LEAF - 1, g[0] + 1, g[j]) == i)
			v.push_back(i);
	}
	cout << v.size()+1 << "\n";
	for (i = 0; i <v.size(); i++){
		j = S.size() - v[i];
		l = g[j];
		r = S.size() - 1;
		while (l <= r){
			m = (l + r) >> 1;
			if (m == g[j])
				l = m + 1;
			else if (get_min(1, 0, LEAF - 1, g[j] + 1, m) >= v[i])
				l = m + 1;
			else r = m - 1;
		}
		cout << v[i] << " " << l-g[j] << "\n";
	}
	cout << S.size() << " " << 1;

	return 0;
}
