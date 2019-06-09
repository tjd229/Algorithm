//math, dp
#include <stdio.h>
#include <memory.h>
#define ll long long
const int mod = 998244353;
int n, m;
int a[200001], w[200001];
int posi, neg;
int e[5001][5001];//now,+d,-d
int une[5001][5001];
ll inv[10001];
int like(int l, int dis, int cnt) {
	if (cnt >= m) return 1;
	if (w == 0) return 0;
	
	if (e[l][dis] == -1) {
		ll d = 0;
		//int deno = posi + l + neg - dis;
		int deno = l - dis + 5000;
		ll p = (posi + l + 1)*inv[deno] % mod;
		p = like(l + 1, dis, cnt + 1)*p%mod;
		d = (d + p) % mod;

		p = (neg - dis)*inv[deno] % mod;
		p = like(l, 1 + dis, cnt + 1)*p%mod;
		d = (d + p) % mod;
		e[l][dis] = d;
	}
	return e[l][dis];
}
ll dislike(int l, int dis, int cnt) {
	if (cnt >= m) return 1;
	if (w == 0) return 0;
	if (une[l][dis] == -1) {
		ll d = 0;
		//int deno = posi + l + neg - dis;
		int deno = l - dis + 5000;
		ll p = (posi + l)*inv[deno] % mod;
		p = dislike(l + 1, dis, cnt + 1)*p%mod;
		d = (d + p) % mod;

		p = (neg - dis - 1)*inv[deno] % mod;
		p = dislike(l, 1 + dis, cnt + 1)*p%mod;
		d = (d + p) % mod;
		une[l][dis] = d;
	}
	return une[l][dis];
}
int main() {
	int i;
	for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) scanf("%d", a + i);
	for (i = 1; i <= n; ++i) {
		scanf("%d", w + i);
		if (a[i]) posi += w[i];
		else neg += w[i];
	}
	for (i = 0; i <= 10000; ++i) {
		int e = mod - 2;
		inv[i] = 1;
		ll base = posi+neg+i-5000;
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
		if (a[i]) printf("%I64d\n", (ll)w[i] * like(0, 0, 0) % mod);
		else printf("%I64d\n", (ll)w[i] * dislike(0, 0, 0) % mod);
	}
	return 0;
}