//category : string, SA, cnt sort, dp
//reference : http://codeforces.com/contest/822/submission/31234580

#include <string>
#include <iostream>
#include <memory.h>
using namespace std;
int g[18][200002];
int s_ix[200002];
int tmp[200002];
int cnt[200002];
int dp[31][100001];
int d, k;
int n, m;
string s, t;
int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a > b ? a : b; }
bool cmp(int a, int b){
	if (g[k][a] != g[k][b]) return g[k][a] < g[k][b];
	return g[k][a + d] < g[k][b + d];
}
int get_lcp(int a,int b,int _d,int _k){
	if (a < 0 || b < 0) return 0;
	if (a > s.size() || b>s.size()) return 0;
	if (_k == k&&a == b) return s.size() - s_ix[g[k][a] - 1];
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
int main(){
	int i,j;
	int x;
	int len;
	bool ans = false;
	cin >> n >> s >> m >> t;
	cin >> x;
	s += "#" + t;
	for (i = 0; i < s.size(); i++){
		s_ix[i] = i;
		g[0][i] = s[i];
	}
	d = 1;
	do{
		cnt_sort(s.size());

		g[k + 1][s_ix[0]] = 1;
		for (i = 1; i < s.size(); i++)
			g[k + 1][s_ix[i]] = g[k + 1][s_ix[i-1]] + cmp(s_ix[i - 1], s_ix[i]);
		d <<= 1;
		k++;
		
	} while (g[k][s_ix[s.size() - 1]] != s.size());
	
	for (i = 0; i < x; i++){
		for (j = 0; j < n; j++){
			len = get_lcp(j,dp[i][j]+n+1,d,k);
			dp[i][j + 1] = max(dp[i][j], dp[i][j + 1]);
			dp[i + 1][j + len] = max(dp[i + 1][j + len], dp[i][j] + len);
		}
	}
	for (i = 1; i <= x; i++){
		for (j = 0; j <= n; j++){
			ans |= (dp[i][j] == m);
		}
	}
	cout << (ans ? "YES" : "NO");
	

	return 0;
}