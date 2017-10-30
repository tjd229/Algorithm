//category : string, SA, cnt sort

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <memory.h>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int g[20][500001];
int tmp[500001];
int cnt[500001];
int s_ix[500001];
int k, d;
string p;
bool cmp(int a, int b){
	if (g[k][a] != g[k][b]) return g[k][a] < g[k][b];
	return g[k][a + d] < g[k][b + d];
}
void cnt_sort(int len){
	int i;
	memset(tmp, 0, sizeof(tmp));
	memset(cnt, 0, sizeof(cnt));
	for (i = 0; i < len; i++)
		cnt[g[k][min(len, s_ix[i] + d)]]++;
	for (i = 1; i <= 'z' || i < len; i++)
		cnt[i] += cnt[i - 1];
	for (i=len - 1; i >= 0; i--)
		tmp[--cnt[g[k][min(len, s_ix[i] + d)]]] = s_ix[i];

	memset(cnt, 0, sizeof(cnt));
	for (i = 0; i < len; i++)
		cnt[g[k][tmp[i]]]++;
	for (i = 1; i <= 'z' || i < len; i++)
		cnt[i] += cnt[i - 1];
	for (i=len - 1; i >= 0; i--)
		s_ix[--cnt[g[k][tmp[i]]]] = tmp[i];

}
int get_lcp(int a, int b, int _d, int _k){
	if (k == _k&&a == b) return p.size() - s_ix[g[k][a]];
	int lcp = 0;
	while (_k != 0 && g[_k][a] != g[_k][b]){
		_k--;
		_d >>= 1;
	}
	if (g[_k][a] == g[_k][b])
		lcp += _d + get_lcp(a+_d,b+_d,_d,_k);
	return lcp;
}
int main(){
	int i, j,l;
	int end;
	int lcp;
	bool flag;
	
	vector<pii > candi;
	vector<int> pre;
	ios::sync_with_stdio(false);
	cin.tie();
	cin >> p;
	for (i = 0; i < p.size(); i++)
	{
		s_ix[i] = i;
		g[0][i] = p[i];
	}

	d = 1;
	do{
		cnt_sort(p.size());
		g[k + 1][s_ix[0]] = 1;
		for (i = 1; i < p.size(); i++)
			g[k + 1][s_ix[i]] = g[k + 1][s_ix[i-1]] + cmp(s_ix[i-1],s_ix[i]);
		d <<= 1;
		k++;
	} while (p.size()!=g[k][s_ix[p.size()-1]]);
	for (i = 0; i < p.size(); i++) g[k][i]--;

	set<int> st;
	for (i = 0; i < p.size(); i++){
		lcp = get_lcp(0, i, d, k);
		if (lcp == p.size() - i){
			pre.push_back(lcp);
		}
		
		candi.push_back(mp(lcp, i+1));
		st.insert(i+1);
		
	}
	sort(candi.begin(), candi.end());
	sort(pre.begin(), pre.end());
	if (pre.size() == p.size()){
		cout << 1;
		return 0;
	}
	vector<int> v;
	i = j = 0;
	for (j = 0; j < pre.size(); j++){
		lcp = pre[j];
		flag = true;
		while (i<candi.size() && candi[i].first < lcp){
			v.push_back(candi[i].second);
			st.erase(candi[i].second);
			i++;
		}
		for (l = 0; l < v.size(); l++){
			st.erase(v[l]);
		}
		st.insert(0);
		st.insert(p.size());

		while (!v.empty()){
			auto it = st.lower_bound(v.back());
			int nxt = *it;
			it--;
			int curr = *it;
			flag &= ((nxt - curr) <= lcp);
			v.pop_back();
		}
		
		if (flag){
			cout << lcp;
			return 0;
		}
		
	}
	cout << p.size();
	return 0;

}