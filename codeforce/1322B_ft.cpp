//math, ft
#include <stdio.h>
#include <memory.h>
#define reg register
const int LEAF = 1 << 25;
int ft[LEAF];
int a[400001];
int n;
void upd(int ix, int d) {
	while (ix < LEAF) {
		ft[ix] += d;
		ix += (ix&-ix);
	}
}
int tox(int x) {
	if (x < 0) return 0;
	if (x >= LEAF) x = LEAF - 1;
	int sum = 0;
	while (x) {
		sum += ft[x];
		x -= (x&-x);
	}
	return sum;
}
int sum(int s,int e) {
	return tox(e) - tox(s - 1);
}
 
 
int calc_bit(int k) {
	memset(ft, 0, sizeof(ft));
	int s = 1 << k;
	int mask = (s<<1) - 1;
	int cnt = 0;
	int i;
	for (upd(1 + (mask&a[1]), 1), i = 2; i <= n; ++i) {
		int res = mask & a[i];
		cnt ^= sum(s - res + 1, mask - res + 1) & 1;
		cnt ^= sum(s + mask + 1 - res +1, LEAF - 1) & 1;
 
		upd( res+1, 1);
	}
 
	
	//printf("%d:%d\n",k,cnt);
	return cnt;
}
int main() {
	reg int i;
	
	//n = 400000;
	//for (i = 1; i <= n; ++i) a[i] = i + 1;
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i);
	int ans = 0;
	for (i = 0; i < 25; ++i)
		ans += (calc_bit(i) << i);
	printf("%d",ans);
	return 0;
}