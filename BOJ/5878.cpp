//category : dp, st, lazy propagation

#include <stdio.h>
#include <memory.h>
#include <stack>
#define pii pair<int,int>
#define ll long long
using namespace std;
const int LEAF = 1 << 17;
ll dh[LEAF + LEAF], st[LEAF + LEAF];
int h[LEAF + LEAF];
int lazy[LEAF + LEAF];
ll d[100001];
int s[100001];
int W[100001],H[100001];

ll min(ll a, ll b){ return a < b ? a : b; }
int max(int a, int b){ return a < b ? b : a; }
void propagate(int ix){
	if (lazy[ix] != 0){
		h[ix] = lazy[ix];
		if (ix < LEAF){
			lazy[ix + ix] = lazy[ix + ix + 1] = lazy[ix];
		}
		st[ix] = h[ix] + dh[ix];
		lazy[ix] = 0;
	}
}
void update(int ix, int s, int e, int from, int to, ll d, int H){
	if (lazy[ix] != 0) propagate(ix);
	if (e < from || to < s) return;

	if (from <= s&&to >= e){
		if (d > 0) dh[ix] = d;
		lazy[ix] = H;
		propagate(ix);
	}
	else{
		update(ix + ix, s, (s + e) >> 1, from, to, d, H);
		update(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to, d, H);
		st[ix] = min(st[ix + ix], st[ix + ix + 1]);
		dh[ix] = min(dh[ix + ix], dh[ix + ix + 1]);
		h[ix] = max(h[ix + ix], h[ix + ix + 1]);
	}
}
ll min_d(int ix, int s, int e, int from, int to){
	if (lazy[ix] != 0) propagate(ix);
	if (e < from || to < s) return 1e16+1;
	if (from <= s&&to >= e) return st[ix];
	return min(min_d(ix + ix, s, (s + e) >> 1, from, to), min_d(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to));
}
int main(){
	int i;
	int N,L;
	int from = 0;
	int wsum = 0;
	stack<pii > stk;
	int p;
	for (scanf("%d%d", &N,&L), i = 1; i <= N; i++){
		scanf("%d%d", H + i, W + i);
		wsum += W[i];
		while (wsum > L){
			wsum -= W[++from];
		}
		p = i;
		while (!stk.empty() && stk.top().first <= H[i]){
			p = stk.top().second;
			stk.pop();
		}
		stk.push({ H[i], p });
		update(1, 0, LEAF - 1, p, i, 0, H[i]);
		update(1, 0, LEAF - 1, i, i, d[i - 1], H[i]);
		d[i] = min_d(1, 0, LEAF - 1, from + 1, i);

	}
	
	printf("%lld", d[N]);
	return 0;
}
