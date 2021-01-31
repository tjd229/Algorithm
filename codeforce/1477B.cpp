//st, lazy propagation
#include <stdio.h>
#include <vector>
#define pii pair<int,int>
using namespace std;
const int LEAF = 1 << 18;
int st[LEAF + LEAF],tgt[LEAF+LEAF];
int s[200001], f[200001];
int l[200001], r[200001];
void propagate(int ix,int len) {
	if (tgt[ix] < 0) return;
	st[ix]=len* tgt[ix];
	if (ix < LEAF) {
		tgt[ix + ix] = tgt[ix];
		tgt[ix + ix + 1] = tgt[ix];
	}
	tgt[ix] = -1;
}
void init(int ix,int s,int e,int from,int to) {
	st[ix] = 0; tgt[ix] = -1;
	if (e < from || to < s) return;
	if (ix < LEAF) {
		init(ix + ix, s, (s + e) >> 1, from, to);
		init(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to);
	}
}
void upd(int ix, int val) {
	while (ix) {
		st[ix] += val;
		ix >>= 1;
	}
}
int rangesum(int ix, int s, int e, int from, int to) {
	propagate(ix,e-s+1);
	if (e < from || to < s) return 0;
	if (from <= s && e <= to) return st[ix];
	return rangesum(ix + ix, s, (s + e) >> 1, from, to)
		+ rangesum(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to);
}
void make_eq(int ix, int s, int e, int from, int to,int val) {
	propagate(ix,e-s+1);
	if (e < from || to < s) return;
	if (from <= s && e <= to) {
		tgt[ix] = val;
		propagate(ix,e-s+1);
		return;
	}
	make_eq(ix + ix, s, (s + e) >> 1, from, to,val);
	make_eq(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to,val);
	st[ix] = st[ix + ix] + st[ix + ix + 1];
}
void push(int ix, int s, int e, int from, int to) {
	propagate(ix, e - s + 1);
	if (e < from || to < s) return;
	if (ix < LEAF) {
		push(ix + ix, s, (s + e) >> 1, from, to);
		push(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to);
	}
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i,n, q;
		for (scanf("%d%d", &n, &q), i = 1; i <= n; ++i) scanf("%1d", s + i);
		init(1, 0, LEAF - 1, 1, n);
		for (i = 1; i <= n; ++i) {
			scanf("%1d", f + i);
			upd(LEAF + i, f[i]);
		}
		for (i = 0; i < q; ++i) scanf("%d%d",l+i,r+i);
		bool flag = 1;
		for (i = q - 1; i >= 0 && flag; --i) {
			int sum = rangesum(1, 0, LEAF - 1, l[i], r[i]);
			int len = r[i] - l[i] + 1;
			int half = (len >> 1) + (len & 1);//for strictly less than
			int cnt1 = sum, cnt0 = len - cnt1;
			if (cnt0 < half) {
				//make1
				make_eq(1, 0, LEAF - 1, l[i], r[i], 1);
			}
			else if (cnt1 < half) {
				//make0
				make_eq(1, 0, LEAF - 1, l[i], r[i], 0);
			}
			else flag = 0;
			//push(1, 0, LEAF - 1, 1, n);
			//for (int j = 1; j <= LEAF + LEAF; ++j)
			//	printf("%d:%d,%d\n",j,st[j],tgt[j]);
			////for (int j = 1; j <= n && flag; ++j)
			//	//printf("%d", st[j + LEAF]);
			//puts("");
		}
		push(1, 0, LEAF - 1, 1, n);
		/*for (i = 1; i <= n && flag; ++i)
			printf("%d",st[i+LEAF]);
		puts("");*/
		for (i = 1; i <= n && flag; ++i)
			if (s[i] != st[i+LEAF]) flag = 0;
		printf("%s\n",flag? "YES":"NO");
	}
	return 0;
}