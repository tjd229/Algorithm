//category : string, SA, cnt sort, djs

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
int g[200001];
int tmp[200001];
int cnt[200001];
int s_ix[200001];
int lcp[200002];
int p[200001];
bool cover[200001];
int d;

bool cmp(int a, int b){
	if (g[a] != g[b]) return g[a] < g[b];
	return g[a + d] < g[b + d];
}
void cnt_sort(int len){
	int i;
	memset(tmp, 0, sizeof(tmp));
	memset(cnt, 0, sizeof(cnt));
	for (i = 0; i < len; i++)
		cnt[g[min(len, s_ix[i] + d)]]++;
	for (i = 1; i < len || i <= 'z'; i++)
		cnt[i] += cnt[i - 1];
	for (i = len - 1; i >= 0; i--)
		tmp[--cnt[g[min(len, s_ix[i] + d)]]] = s_ix[i];
	memset(cnt, 0, sizeof(cnt));
	for (i = 0; i < len; i++)
		cnt[g[tmp[i]]]++;
	for (i = 1; i < len || i <= 'z'; i++)
		cnt[i] += cnt[i - 1];
	for (i = len - 1; i >= 0; i--)
		s_ix[--cnt[g[tmp[i]]]] = tmp[i];
}
int find(int a){
	if (a != p[a]) p[a] = find(p[a]);
	return p[a];
}
void join(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	//if (s_ix[a] > s_ix[b]) swap(a,b);

	p[b] = a;
	tmp[a] += tmp[b];
}
int main(){
	int i, j;
	int n;
	long long ans = 0;
	string s, t;
	vector<pii > v;
	cin >> n >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	for (i = 0; i < s.size(); i++){
		g[i] = s[i];
		s_ix[i] = i;
	}
	d = 1;
	do{
		cnt_sort(s.size());
		tmp[s_ix[0]] = 1;
		for (i = 1; i < s.size(); i++)
			tmp[s_ix[i]] = tmp[s_ix[i - 1]] + cmp(s_ix[i - 1], s_ix[i]);
		for (i = 0; i < s.size(); i++)
			g[i] = tmp[i];
		d <<= 1;
	} while (g[s_ix[s.size() - 1]] != s.size());
	for (i = 0; i < s.size(); i++){
		g[i]--;
		p[g[i]] = g[i];
		tmp[g[i]] = (t[i] == '0');
		ans = max(ans, (long long)tmp[g[i]] * (s.size() - i));
	}
	d = 0;
	for (i = 0; i < s.size(); i++){
		if (g[i] == 0) continue;
		j = s_ix[g[i] - 1];
		d = max(0, d - 1);
		while (i + d < s.size() && j + d < s.size() && s[i + d] == s[j + d])
			lcp[g[i]] = ++d;
		d = lcp[g[i]] - 1;
		if (lcp[g[i]] != 0)
			v.push_back(mp(-lcp[g[i]], g[i]));
	}
	//v.push_back(mp(0,0));
	sort(v.begin(), v.end());
	for (i = 0; i < v.size(); i++){
		j = v[i].second;
		d = lcp[j];

		
		if (j > 0 && (lcp[j] >= lcp[j - 1]||cover[j-1])){
			join(j - 1, j);
		}
		cover[j] = true;
		//printf("%d,%d,%d\n", j, d, tmp[find(j-1)]);
		ans = max(ans, (long long)tmp[find(j-1)] * lcp[j]);
	}
	printf("%I64d", ans);

	return 0;
}
