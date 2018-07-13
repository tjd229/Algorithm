//idea reference : https://github.com/jwvg0425/SoftCon/blob/master/1/G.%20%EC%97%B0%EC%82%B0%20%EC%B5%9C%EC%A0%81%ED%99%94/solution.md
//dp, SA, cnt sort

#include <stdio.h>
#include <memory.h>
const int MX = 1e6;
int S[MX];
int N;
int d, k;
int g[21][MX + 1];
int s_ix[MX];
int cnt[MX];
int tmp[MX];
int F[20][MX];
int L;
int min(int a, int b){ return a < b ? a : b; }
bool cmp(int a, int b){
	if (g[k][a] != g[k][b]) return g[k][a] < g[k][b];
	return g[k][a + d] < g[k][b + d];
}
int get_lcp(int a, int b, int _d, int _k){
	if (k == _k && a == b) return N - s_ix[g[k][a] - 1];
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
	for (i = 0; i < N; i++)
		cnt[g[k][min(N, s_ix[i] + d)]]++;
	for (i = 1; i < N || i <= 2; i++)
		cnt[i] += cnt[i - 1];
	for (i = N - 1; i >= 0; i--)
		tmp[--cnt[g[k][min(N, s_ix[i] + d)]]] = s_ix[i];
	memset(cnt, 0, sizeof(cnt));
	for (i = 0; i < N; i++)
		cnt[g[k][tmp[i]]]++;
	for (i = 1; i < N || i <= 2; i++)
		cnt[i] += cnt[i - 1];
	for (i = N - 1; i >= 0; i--)
		s_ix[--cnt[g[k][tmp[i]]]] = tmp[i];

}

int opF(int l, int r, int c){
	if (c + l == 0) return 0;
	if (F[c][l] != MX + MX) return F[c][l];
	F[c][l] = MX;
	if (l > 0 && r>L &&S[l - 1] == S[r - 1])
		F[c][l] = min(F[c][l], 1 + opF(l - 1, r - 1, c));
	int halfl = l >> 1;
	int halfr = r >> 1;
	if (c>0 && (l & 1) + (r&1) == 0 && cnt[halfl] >= halfl && cnt[halfr] >= halfr && halfr>=L )
		F[c][l] = min(F[c][l], 1 + opF(halfl,halfr,c-1));
	return F[c][l];
}
int main(){
	int i, j;

	for (scanf("%d", &N), i = 0; i < N; i++){
		scanf("%1d", S + i);
		s_ix[i] = i;
		g[0][i] = S[i] + 1;

	}
	g[0][i] = 0;
	d = 1;
	do{
		//std::sort(s_ix, s_ix + N, cmp);
		cnt_sort();
		g[k + 1][s_ix[0]] = 1;
		for (i = 1; i < N; i++)
			g[k + 1][s_ix[i]] = g[k + 1][s_ix[i - 1]] + cmp(s_ix[i - 1], s_ix[i]);
		g[++k][i] = 0;
		d <<= 1;

	} while (g[k][s_ix[N - 1]] != N);
	cnt[0] = N;
	for (i = 1; i < N; i++)
		cnt[i] = get_lcp(0, i, d, k);
	int ans = MX + MX;


	int div = 1 + 1;
	for (int c = 0, div = 1 + 1; div <= N; c++, div = ((div - 1) << 1) + 1){

		if (N%div != 0) continue;

		L = N / div;
		for (i = 0; i <= c; i++) for (j = 0; j <= L; j++) F[i][j] = MX + MX;
		ans = min(ans, opF(L,N,c));
	}

	printf("%d", ans >= MX ? -1 : ans);

	return 0;
}
