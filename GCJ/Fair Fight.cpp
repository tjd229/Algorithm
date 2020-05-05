//st, bs
//https://codingcompetitions.withgoogle.com/codejam/round/0000000000051706/0000000000122838

#include <stdio.h>
#include <memory.h>
const int LEAF = 1 << 17;
int cst[LEAF + LEAF],dst[LEAF+LEAF];
int c[100001];
int bnd[100001],nxt[100001];
void upd(int ix, int val, int *st) {
	st[ix] = val;
	ix >>= 1;
	while (ix) {
		st[ix] = st[ix + ix];
		if (st[ix] < st[ix + ix + 1])
			st[ix] = st[ix + ix + 1];
		ix >>= 1;
	}
}
int range_max(int ix,int s,int e,int from,int to,int *st) {
	if (e < from || to < s) return 0;
	if (from <= s && e <= to)
		return st[ix];
	int l = range_max(ix + ix, s, (s + e) >> 1, from, to, st);
	int r = range_max(ix + ix+1, 1+((s + e) >> 1),e, from, to, st);
	return l < r ? r : l;
}
int main() {
	int tc, T;
	for (scanf("%d", &T), tc = 1; tc <= T; ++tc) {
		memset(cst, 0, sizeof(cst));
		memset(dst, 0, sizeof(dst));
		int i, N, K;
		for (scanf("%d%d", &N, &K), i = 1; i <= N; ++i) {
			scanf("%d", c + i);
			upd(LEAF + i, c[i], cst);
			nxt[c[i]] = N+1;
		}
		for (i = N; i > 0; --i) {
			bnd[i] = nxt[c[i]]-1;
			nxt[c[i]] = i;
		}
		for (i = 1; i <= N; ++i) {
			int d; scanf("%d",&d);
			upd(LEAF + i, d, dst);
		}
		long long ans = 0;
		for (i = 1; i <= N; ++i) {
			int L = -1, R=-1;
			int s = 1, e = i;
			while (s <= e) {
				int m = (s + e) >> 1;
				if (range_max(1, 0, LEAF - 1, m, i, cst) == c[i]
					 && range_max(1, 0, LEAF - 1, m, i, dst)<=c[i]+K) {
					e = m - 1;
					L = m;					
				}
				else s = m + 1;					
			}
			s = i, e = bnd[i];
			while (s <= e) {
				int m = (s + e) >> 1;
				if (range_max(1, 0, LEAF - 1, i,m, cst) == c[i]
					&& range_max(1, 0, LEAF - 1, i, m, dst) <=K+ c[i]) {
					s = 1 + m;
					R = m;
				}
				else e = m - 1;
			}
			//printf("%d:%d~%d\n", i, L, R);
			if (L < 0 || R < 0) continue;
			long long tot = (i - L + 1LL) * (R - i + 1);
			L = -1, R = -1;
			s = 1, e = i;			
			while (s <= e) {
				int m = (s + e) >> 1;
				if (range_max(1, 0, LEAF - 1, m, i, cst) == c[i]
					&& range_max(1, 0, LEAF - 1, m, i, dst) < c[i] - K) {
					e = m - 1;
					L = m;
				}
				else s = 1 + m;
			}
			s = i, e = bnd[i];
			while (s <= e) {
				int m = (s + e) >> 1;
				if (range_max(1, 0, LEAF - 1, i, m, cst) == c[i]
					&& range_max(1, 0, LEAF - 1, i, m, dst) <c[i]-K) {
					s = 1 + m;
					R = m;
				}
				else e = m - 1;
			}
			long long cnt = 0;
			if(L>0 && R>0)
				cnt= (i - L + 1LL) * (R - i + 1);
			ans += tot - cnt;
		}
		printf("Case #%d: %lld\n",tc,ans);
	}
	return 0;
}
