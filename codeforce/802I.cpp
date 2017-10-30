//category : string, SA, cnt sort
//idea reference : http://codeforces.com/contest/802/submission/31190795

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <memory.h>
#define ll long long

#define mp make_pair
#define pii pair<int,int>
using namespace std;
string s;
int g[100001];
int cnt[100001];
int tmp[100001];
int lcp[100001];
int s_ix[100000];
int d;
bool cmp(int a, int b){
	if (g[a] != g[b]) return g[a] < g[b];
	return g[a + d] < g[b + d];
}
void cnt_sort(int len){
	int i;
	memset(cnt, 0, sizeof(cnt));
	memset(tmp, 0, sizeof(tmp));
	for (i = 0; i < len; i++)
		cnt[g[min(len, s_ix[i] + d)]]++;
	for (i = 1; i <= 'z' || i < len; i++)
		cnt[i] += cnt[i - 1];
	for (i = len-1; i >=0; i--)
		tmp[--cnt[g[min(len, s_ix[i] + d)]]] = s_ix[i];

	memset(cnt, 0, sizeof(cnt));
	for (i = 0; i < len; i++)
		cnt[g[tmp[i]]]++;
	for (i = 1; i <= 'z' || i < len; i++)
		cnt[i] += cnt[i - 1];
	for (i = len - 1; i >= 0; i--)
		s_ix[--cnt[g[tmp[i]]]] = tmp[i];

}

int main(){
	int i, j,k;
	int T;
	int val;
	int offset;
	ll ans = 0;
	cin >> T;
	while (T--){
		ans = 0;
		cin >> s;
		for (i = 0; i < s.size(); i++){
			g[i] = s[i];
			s_ix[i] = i;
			ans += i + 1;
		}
		g[i] = 0;
		d = 1;
		
		do{
			cnt_sort(s.size());
			
			tmp[s_ix[0]] = 1;
			for (i = 1; i < s.size(); i++)
				tmp[s_ix[i]] = tmp[s_ix[i - 1]] + cmp(s_ix[i - 1], s_ix[i]);
			tmp[i] = 0;
			d <<= 1;
			for (i = 0; i < s.size(); i++)
				g[i] = tmp[i];
		} while (g[s_ix[s.size()-1]]!=s.size());
		for (i = 0; i < s.size(); i++) g[i]--;
		d = 0;
		vector<pii > v;
		set<int> st;
		for (i = 0; i < s.size(); i++){
			if (g[i] == 0) continue;
			j = s_ix[g[i] - 1];
			d = max(d - 1, 0);
			lcp[g[i]] = 0;
			while (i + d < s.size() && j + d < s.size() && s[i + d] == s[j + d])
				lcp[g[i]] = ++d;
			d = lcp[g[i]] - 1;
			if (lcp[g[i]] == 0)
				st.insert(g[i]);
			else
				v.push_back(mp(lcp[g[i]],g[i]));
		}
		/*for (i = 0; i < s.size(); i++){
			cout << lcp[i] << " ";
		}
		for (i = 0; i < s.size(); i++){
			cout << g[i] << " ";
		}*/
		lcp[i] = 0;
		st.insert(0);
		st.insert(s.size());
		sort(v.begin(), v.end());
		//cout << v.size() << endl;
		for (i = 0; i < v.size(); i++){
			st.insert(v[i].second);
			
			auto r = st.find(v[i].second);
			auto l = st.find(v[i].second);
			r++;
			l--;
			offset = max(lcp[*l], lcp[*r]);
			val = (*r - *l);
			//cout << val << endl;
			ans += (v[i].first-offset)*((ll)val*val-val);
		}

		cout << ans << "\n";

	}


	return 0;
}