//st
#include <stdio.h>
#define ll long long
const int LEAF = 1 << 20;
const int mod = 1e9 + 7;
ll st[LEAF + LEAF];
void upd(int ix, int val) {
	st[ix] = val;
	ix >>= 1;
	while (ix) {
		st[ix] = st[ix + ix] * st[ix + ix + 1] % mod;
		ix >>= 1;
	}
}
int mul(int ix, int s, int e, int from, int to) {
	if (e < from || to < s) return 1;
	if (from <= s && e <= to) return st[ix];
	ll l = mul(ix + ix, s, (s + e) >> 1, from, to);
	ll r = mul(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to);
	return l * r%mod;
}
int main() {
	int i, N, M, K;
	for (scanf("%d%d%d", &N, &M, &K), i = 1; i <= N; ++i) {
		int val; scanf("%d",&val);
		upd(LEAF + i, val);
	}
	for (int MK = M + K; MK--;) {
		int a, b, c; scanf("%d%d%d",&a,&b,&c);
		if (--a) printf("%d\n",mul(1,0,LEAF-1,b,c));
		else upd(LEAF + b, c);
	}
	return 0;
}