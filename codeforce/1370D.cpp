//bs, greedy

#include <stdio.h>
int a[200001];
int pick(int b,int k,int n,int *a) {
	int sz = 0;
	for (int i = 0; i < n && sz<k;) {
		if (a[i] <= b) {
			i += 2;
			++sz;
		}
		else ++i;		
	}
	return sz >= k;
}
int main() {
	int i, n, k;
	int mn = 1e9, mx = 0;
	for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		if (mn > a[i]) mn = a[i];
		if (mx < a[i]) mx = a[i];
	}
	int ssz = k >> 1;
	int fsz = ssz + (k & 1);
	//first group
	int l = mn, r = mx;
	int f = mx;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (pick(m, fsz, n-(1-(k&1)), a + 1)) r = m - 1,f=m;
		else l = m + 1;
	}
	//second group
	l = mn, r = mx;
	int s = mx;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (pick(m, ssz, n-1-(k&1), a + 1 + 1)) r = m - 1, s = m;
		else l = 1 + m;
	}
	//printf("%d,%d\n",f,s);
	int ans = f < s ? f : s;
	printf("%d",ans);
 
	return 0;
}