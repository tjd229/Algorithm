//category : string, SA, cnt sort

#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
int d, k;
int g[21][1000001];
int s_ix[1000000];
int cnt[1000000];
int tmp[1000000];
string S;
bool cmp(int a, int b){
	if (g[k][a] != g[k][b]) return g[k][a] < g[k][b];
	return g[k][a + d] < g[k][b + d];
}
int get_lcp(int a, int b, int _d, int _k){
	if (k == _k&&a == b) return S.size() - s_ix[g[k][a]-1];
	int lcp = 0;
	while (_k != 0 && g[_k][a] != g[_k][b]){
		_k--;
		_d >>= 1;
	}
	if (g[_k][a] == g[_k][b])
		lcp += _d + get_lcp(a + _d, b + _d, _d, _k);
	return lcp;
}
void cnt_sort(){
	int i;
	memset(cnt, 0, sizeof(cnt));
	memset(tmp, 0, sizeof(tmp));
	for (i = 0; i < S.size(); i++)
		cnt[g[k][min((int)S.size(), s_ix[i] + d)]]++;
	for (i = 1; i < S.size() || i < 255; i++)
		cnt[i] += cnt[i - 1];
	for (i = S.size() - 1; i >= 0; i--)
		tmp[--cnt[g[k][min((int)S.size(), s_ix[i] + d)]]] = s_ix[i];
	memset(cnt,0,sizeof(cnt));
	for (i = 0; i < S.size(); i++)
		cnt[g[k][tmp[i]]]++;
	for (i = 1; i < S.size() || i <= 255; i++)
		cnt[i] += cnt[i - 1];
	for (i = S.size() - 1; i >= 0; i--)
		s_ix[--cnt[g[k][tmp[i]]]] = tmp[i];

}
int main(){
	int i;
	int M;
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> S >> M;
	reverse(S.begin(), S.end());
	for (i = 0; i < S.size(); i++){
		s_ix[i] = i;
		g[0][i] = S[i];
	}
	g[0][i] = 0;
	d = 1;
	do{
		//sort(s_ix, s_ix + S.size(), cmp);
		cnt_sort();
		g[k + 1][s_ix[0]] = 1;
		for (i = 1; i < S.size(); i++)
			g[k + 1][s_ix[i]] = g[k + 1][s_ix[i - 1]] + cmp(s_ix[i - 1], s_ix[i]);
		g[k + 1][i] = 0;
		k++;
		d <<= 1;
	} while (g[k][s_ix[S.size() - 1]] != S.size());
	while (M--){
		cin >> i;
		cout << get_lcp(0, S.size() - i, d, k) << "\n";
	}


	return 0;
}