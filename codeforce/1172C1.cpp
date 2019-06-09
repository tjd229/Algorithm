//math, dp
#include <stdio.h>
#include <memory.h>
#define ll long long
const int mod = 998244353;
int n, m;
int a[51], w[51];
int posi, neg;
ll e[101][51][51];//now,+d,-d
ll une[101][51][51];
ll inv[4000];
ll like(int w,int l,int dis,int cnt) {
	if (cnt >= m) return w;
	if (w == 0) return 0;
	ll &d = e[w][l][dis];
	if (d == -1) {		
		d = 0;
		int deno = posi + l+neg - dis;
		ll p = w * inv[deno] % mod;		
		p= like(w + 1, l + 1, dis, cnt + 1)*p%mod;
		d = (d + p) % mod;
		
		p = (posi+l - w)*inv[deno] % mod;
		p = like(w, l + 1, dis, cnt + 1)*p%mod;
		d = (d + p) % mod;

		p = (neg-dis)*inv[deno] % mod;
		p = like(w, l, 1+dis, cnt + 1)*p%mod;
		d = (d + p) % mod;
	}
	return d;
}
ll dislike(int w, int l, int dis, int cnt) {
	if (cnt >= m) return w;
	if (w == 0) return 0;
	ll &d = une[w][l][dis];
	if (d == -1) {
		d = 0;
		int deno = posi + l + neg - dis;
		ll p = w * inv[deno] % mod;
		p = dislike(w - 1, l, 1+dis, cnt + 1)*p%mod;
		d = (d + p) % mod;

		p = (posi + l)*inv[deno] % mod;
		p = dislike(w, l + 1, dis, cnt + 1)*p%mod;
		d = (d + p) % mod;

		p = (neg - dis-w)*inv[deno] % mod;
		p = dislike(w, l, 1 + dis, cnt + 1)*p%mod;
		d = (d + p) % mod;
	}
	return d;
}
int main() {
	int i;
	for (scanf("%d%d", &n, &m), i = 1; i <=n ; ++i) scanf("%d",a+i);
	for (i = 1; i <= n; ++i) {
		scanf("%d", w + i);
		if (a[i]) posi += w[i];
		else neg += w[i];
	}
	for (inv[0] = i = 1; i < 4000; ++i) {
		int e = mod-2;
		inv[i] = 1;
		ll base = i;
		while (e) {
			if (e & 1) 
				inv[i] = inv[i] * base%mod;
			e >>= 1;
			base = base * base%mod;
		}
	}
	memset(e, -1, sizeof(e));
	memset(une, -1, sizeof(une));
	for (i = 1; i <= n; ++i) {
		if (a[i]) printf("%I64d\n", like(w[i], 0, 0, 0));
		else printf("%I64d\n", dislike(w[i], 0, 0, 0));
	}
	return 0;
}