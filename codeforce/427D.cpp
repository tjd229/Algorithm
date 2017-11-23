//category : string, SA, cnt sort

#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
int g[10002];
int cnt[10002];
int tmp[10002];
int s_ix[10002];
int lcp[10003];
int d;
int bnd;
int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a > b ? a : b; }
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
	for (i = 1; i <= 'z' || i < len; i++)
		cnt[i] += cnt[i - 1];
	for (i = len - 1; i >= 0; i--)
		tmp[--cnt[g[min(len, s_ix[i] + d)]]] = s_ix[i];
	memset(cnt,0,sizeof(cnt));
	for (i = 0; i < len; i++)
		cnt[g[tmp[i]]]++;
	for (i = 1; i <= 'z' || i < len; i++)
		cnt[i] += cnt[i - 1];
	for (i = len - 1; i >= 0; i--)
		s_ix[--cnt[g[tmp[i]]]] = tmp[i];
}
bool valid(int x1,int x2){
	if (x1 > x2){
		int t = x1;
		x1 = x2;
		x2 = t;
	}
	return x1 < bnd&&bnd < x2;
}
int main(){
	int i,j;
	string s1, s2;
	cin >> s1 >> s2;
	bnd = s1.size();
	//reverse(s1.begin(), s1.end());
	//reverse(s2.begin(), s2.end());
	s1 += "#" + s2;
	for (i = 0; i < s1.size(); i++){
		s_ix[i] = i;
		g[i] = s1[i];
	}
	d = 1;
	do{
		cnt_sort(s1.size());
		tmp[s_ix[0]] = 1;
		for (i = 1; i < s1.size(); i++)
			tmp[s_ix[i]] = tmp[s_ix[i - 1]] + cmp(s_ix[i-1],s_ix[i]);
		for (i = 0; i < s1.size(); i++)
			g[i] = tmp[i];
		d <<= 1;
	} while (s1.size() != g[s_ix[s1.size()-1]]);
	for (i = 0; i < s1.size(); i++) g[i]--;
	d = 0;
	for (i = 0; i < s1.size(); i++){
		if (g[i] == 0) continue;
		j = s_ix[g[i] - 1];
		d = max(d - 1, 0);
		while (i + d < s1.size() && j + d < s1.size() && s1[i + d] == s1[j + d])
			lcp[g[i]] = ++d;
		d = lcp[g[i]] - 1;
		
	}
	int ans = 1e4+1;
	for (i = 1; i < s1.size(); i++){
		if (lcp[i] == 0) continue;
		if (lcp[i - 1]<lcp[i] && lcp[i]>lcp[i + 1]){
			if (valid(s_ix[i - 1], s_ix[i]))
				ans = min(ans, max(lcp[i - 1],lcp[i+1]) + 1);

		}
			
	}
	if (ans > 1e4) ans = -1;
	cout << ans;

	return 0;
}
