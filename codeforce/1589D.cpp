//bs
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[6] = { 0,2,1,5,4,3 };
long long ask(int l, int r) {
	if (l == r) return 0;
	printf("? %d %d\n", l, r); fflush(stdout);
	long long x; scanf("%I64d", &x);
	return x;
}
 
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, j,k,n; scanf("%d",&n);
		i = 1; k = n;
		
		int l = 1, r = n-1;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (ask(m,n) == 0) {
				k = m;
				r = m - 1;
			}
			else l=1+m;
		}
		long long t1 = ask(1, k), t2 = ask(1, k - 1);
		long long d = t1 - t2;
		j = k - d;
		t1 = ask(1, j-1), t2 = ask(1, j - 2);
		d = t1 - t2;
		i = j - 1 - d;
		printf("! %d %d %d\n", i, j, k); fflush(stdout);
	}
 
	return 0;
}