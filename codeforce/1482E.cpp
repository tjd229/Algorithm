//dp, st
#include <stdio.h>
#define ll long long
const int LEAF = 1 << 19;
const ll inf = 1e18;
int st[LEAF + LEAF]; 
ll lst[LEAF + LEAF];
ll d[300001];
int h[300001], b[300001];
template<typename T>
void upd(int ix,T val, T *st) {
	st[ix] = val; ix >>= 1;
	while (ix) {
		st[ix] = st[ix + ix];
		if (st[ix] < st[ix + ix + 1]) st[ix]=st[ix + ix + 1];
		ix >>= 1;
	}
}
template<typename T>
T rmx(int ix, int s, int e, int from, int to, T* st, ll inf = inf) {
	if (s > e) return -inf;
	if (to<s || e<from) return -inf;
	if (from <= s && e <= to) return st[ix];
	int m = (s + e) >> 1;
	
	T l = rmx(ix + ix, s, m, from, to,st,inf);
	T r = rmx(ix + ix + 1, m + 1, e, from, to,st,inf);
	return l < r ? r : l;
}
inline ll max(ll a, ll b) { return a < b ? b : a; }
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",h+i);
	for (i = 1; i <= n; ++i) scanf("%d",b+i);
	d[1] = b[1]; upd(LEAF+h[1], 1, st); upd(LEAF+1, d[1], lst);
	
	for (i = 2; i <= n; ++i) {
		int mx = rmx(1, 0, LEAF - 1, 0, h[i] - 1, st,0);
		ll dmx = rmx(1, 0, LEAF - 1, mx, i - 1, lst);
		//printf("%d~%d\n",0,h[i]-1);
		//printf("%d,%lld\n",mx,dmx);
		
		d[i] = dmx + b[i];
		if (mx > 0) d[i] = max(d[i], d[mx]);
		//printf("%d:%lld\n",i,d[i]);
		upd(LEAF+h[i], i, st); upd(LEAF+i, d[i], lst);
	}
 
	printf("%I64d\n",d[n]);
 
	return 0;
}