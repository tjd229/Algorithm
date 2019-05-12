//geometry, ccw, d&c
#include <stdio.h>
#include "trilib.h"
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
using namespace std;
int piv = 1;
int u[40010], d[40010];
int hu[40010], hd[40010];
int tmp[40010],ans[40010];
int usz, dsz;
int husz, hdsz;
int sz;
bool cmp(int a,int b) {
	return is_clockwise(piv, b, a);
}
void make_hull(int &hsz,int *h, int &vsz,int *v) {
	int i; hsz = 0;
	for (i = 0; i < 2 && i < vsz; ++i) h[hsz++] = v[i];
	for (; i < vsz; ++i) {
		while (hsz > 1 && is_clockwise(h[hsz - 2], h[hsz - 1], v[i]))
			--hsz;
		h[hsz++] = v[i];
	}
}
void msort(int s,int e,int *a) {
	if (s >= e) return;
	int m = (s + e) >> 1;
	msort(s, m, a); msort(m + 1, e, a);
	int l = s, r = m + 1;
	for (int i = s; i <= e; ++i) {
		if (l > m) tmp[i] = a[r++];
		else if (r > e) tmp[i] = a[l++];
		else tmp[i]= is_clockwise(piv, a[r], a[l]) ? a[l++] : a[r++];
	}
	for (int i = s; i <= e; ++i) a[i] = tmp[i];
}
int main() {
	int n = get_n();//[1,n]
	
	
	for (int i = 3; i <= n; ++i) {
		if (is_clockwise(1, 2, i)) d[dsz++] = i;
		else u[usz++] = i;
	}
	msort(0, dsz - 1, d); msort(0, usz - 1, u);
	//sort(d, d + dsz, cmp);
	//sort(u, u + usz, cmp);
	make_hull(husz, hu, usz, u);
	make_hull(hdsz, hd, dsz, d);

	hu[husz++] = 1;
	for (int i = 0; i < hdsz; ++i) hu[husz++] = hd[i];
	hu[husz++] = 2;
	make_hull(sz, ans, husz, hu);

	bool flag = 1;
	int pad = 0;
	while (flag) {
		flag = 0;					
		while (sz-pad>2 && is_clockwise(ans[sz- 2], ans[sz - 1], ans[pad]))
			--sz,flag=1;	
		while (sz - pad > 2 && is_clockwise(ans[sz - 1], ans[pad], ans[pad+1]))
			++pad, flag = 1;
	}
	give_answer(sz-pad);
	return 0;
}