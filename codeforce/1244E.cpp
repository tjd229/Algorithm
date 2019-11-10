//line sweeping
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
int a[100001];
int n;
int push(int l,int r,ll k) {
	if (l == r) return 0;
	//printf("%d,%d,%lld\n",l,r,k);
	int lcnt = l;
	int rcnt = n - r + 1;
	if (lcnt < rcnt) {
		ll tor = k / lcnt;
		if (a[l + 1] - a[l] < tor) tor = a[l + 1] - a[l];
		k -= lcnt * tor;
		ll tol = k / rcnt;
		if (a[r] - a[r - 1] < tol) tol = a[r] - a[r - 1];
		int diff = tol + tor;
	//	printf("%lld,%lld\n",tor,tol);
		if (a[r] - a[l] < diff) diff = a[r] - a[l]; //no-duplicatd
		return diff;
	}
	else {
		ll tol = k / rcnt;
		if (a[r] - a[r - 1] < tol) tol = a[r] - a[r - 1];
		k -= rcnt * tol;
		ll tor = k / lcnt;
		if (a[l + 1] - a[l] < tor) tor = a[l + 1] - a[l];
		int diff = tol + tor;
	//	printf("%lld,%lld\n", tor, tol);
		if (a[r] - a[l] < diff) diff = a[r] - a[l]; //no-duplicatd
		return diff;
	}
}
int main() {
	int i;  ll k;
	int l, r;
	for (scanf("%d%I64d", &n, &k), i = 1; i <= n; ++i) scanf("%d",a+i);
	sort(a+1,a+1+n);
	l = 1, r = n;
	while (l < n) {
		ll nxt = (a[l + 1] - a[l]) * (ll)l;
		if (nxt > k) break;
		k -= nxt;
		++l;
	}
	int ans = a[r] - a[l];
	ans -= push(l,r,k);
	if (ans < 0) ans = 0;
	
	while (l && ans) {
		int diff = a[r] - a[l];
		diff -= push(l, r, k);
		if (diff < ans) ans = diff;
		if (ans < 0) ans = 0;
		while (l < r) {
			ll nxt = (a[r] - a[r - 1]) * (n-r+1LL);
			if (nxt > k) break;
			k -= nxt;
			--r;
			//calc diff
			int diff = a[r] - a[l];
			diff -= push(l, r, k);
			//printf("%d~%d(%d:%d),k:%lld\n", l, r, a[l], a[r], k);
			//printf("diff:%d(%d)\n",diff,push(l,r,k));
			if (diff < ans) ans = diff;
			if (ans < 0) ans = 0;
		}
		ll dk = (a[l] - a[l - 1]) * (l-1LL);
		k += dk;
		--l;
	}
	printf("%d",ans);
	return 0;
}