//category : string, SA, cnt sort, bs

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <memory.h>
using namespace std;
int g[19][200001];
int cnt[200001];
int s_ix[200001];
int lcp[100001];
int tmp[200001];
int d, k;
string s;
string N, M;
bool cmp(int a, int b){
	if (g[k][a] != g[k][b]) return g[k][a] < g[k][b];
	return g[k][a + d] < g[k][b + d];
}
int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return -min(-a, -b); }
int get_lcp(int a, int b, int _d, int _k){
	if (a < 0 || b < 0) return 0;
	if (k == _k&&a == b) return s.size() - s_ix[g[k][a] - 1];
	int lcp = 0;
	while (_k != 0 && g[_k][a] != g[_k][b]){
		_k--;
		_d >>= 1;
	}
	if (g[_k][a] == g[_k][b])
		lcp += _d + get_lcp(a + _d, b + _d, _d, _k);
	return lcp;
}
void cnt_sort(int len){
	int i;
	memset(cnt, 0, sizeof(cnt));
	memset(tmp, 0, sizeof(tmp));
	for (i = 0; i < len; i++)
		cnt[g[k][min(len, s_ix[i] + d)]]++;
	for (i = 1; i < len || i <= 'z'; i++)
		cnt[i] += cnt[i - 1];
	for (i = len - 1; i >= 0; i--)
		tmp[--cnt[g[k][min(len, s_ix[i] + d)]]] = s_ix[i];

	memset(cnt, 0, sizeof(cnt));
	for (i = 0; i < len; i++)
		cnt[g[k][tmp[i]]]++;
	for (i = 1; i < len || i <= 'z'; i++)
		cnt[i] += cnt[i - 1];
	for (i = len - 1; i >= 0; i--)
		s_ix[--cnt[g[k][tmp[i]]]] = tmp[i];
}
bool construct(int m){
	set<int> st;
	st.insert(N.size());
	for (int i = N.size() - 1; i >= 0; i--){
		if (lcp[i] < m) continue;
		auto it = st.lower_bound(i+m);
		if (it!=st.end()&&*it <= i + lcp[i]){
			st.insert(i);
			if (i == 0) return true;
		}
	}
	return false;

}
int main(){
	int i, j;
	vector<int> v;
	cin >> N >> M;
	s = M + "#" + N;
	for (i = 0; i < s.size(); i++){
		s_ix[i] = i;
		g[0][i] = s[i];
	}
	d = 1;

	do{
		cnt_sort(s.size());
		g[k + 1][s_ix[0]] = 1;
		for (i = 1; i < s.size(); i++)
			g[k + 1][s_ix[i]] = g[k + 1][s_ix[i - 1]] + cmp(s_ix[i - 1], s_ix[i]);

		d <<= 1;
		k++;
	} while (s.size() != g[k][s_ix[s.size() - 1]]);

	j = -1;
	for (i = 0; i < s.size(); i++){
		if (s_ix[i] > M.size())
			tmp[i] = j;
		else{
			j++;
			v.push_back(i);
		}
	}
	//v.push_back(-1);
	v.push_back(i);
	s_ix[i] = -1;
	
	j = 0;
	for (i = 0; i < s.size(); i++){
		if (s_ix[i] > M.size()){
			lcp[s_ix[i] - M.size() - 1] = max(get_lcp(s_ix[v[tmp[i]]], s_ix[i], d, k), get_lcp(s_ix[i], s_ix[v[tmp[i] + 1]], d, k));
			if (j < lcp[s_ix[i] - M.size() - 1]) j = lcp[s_ix[i] - M.size() - 1];
		}
	}
	int ans=-1,m;
	i = 1;
	while (i <= j){
		m = (i + j )>> 1;
		if (construct(m))
			i = m + 1,ans=m;
		else
			j = m - 1;
	}
	cout << ans;


	return 0;
}