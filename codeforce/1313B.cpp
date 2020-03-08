//greedy
#include <stdio.h>
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int n, x, y; scanf("%d%d%d",&n,&x,&y);
		int mn, mx;
		int fl = x - 1, fr = n - x;
		int sl = y - 1, sr = n-y;
		
		int t1 = fl < sr ? fl : sr;
		int t2 = sl < fr ? sl : fr;
		mx = t1 + t2;
		t1 = fl - t1;
		t2 = sl - t2;
		mx += t1 < t2 ? t1 : t2;
 
		if (fr > 0) --fr;
		if (sr > 0) --sr;
		
		t1 = sl - fr;
		if (t1 < 0) t1 = 0;
		t2 = fl - sr;
		if (t2 < 0) t2 = 0;
		mn = t1 < t2 ? t1 : t2;
		//printf("%d,%d,%d\n",t1,t2,mn);
		mn = t1 + t2 - mn;
 
		printf("%d %d\n",mn+1,mx+1);
	}
	return 0;
}