//dp
#include <set>
#include <stdio.h>
#define ll long long
using namespace std;
set<ll> d[9];
int K;
void monod(int n) {
	int l = 1;
	int r = n-1;
	int base = 0;
	for (int i = 0; i < n; ++i) base = base * 10 + K;
	d[n].insert(base);
	while (l <= r) {
		if (d[l].empty()) monod(l);
		if (d[r].empty()) monod(r);
		for (auto t1 = d[l].begin(); t1 != d[l].end(); ++t1) {
			for (auto t2 = d[r].begin(); t2 != d[r].end(); ++t2) {
				ll res = *t1 + *t2;
				d[n].insert(res);
				res = *t1 - *t2; d[n].insert(res);
				res = *t2 - *t1; d[n].insert(res);
				res = *t2 * (*t1); d[n].insert(res);
				if (*t2 != 0) {
					res = *t1 / (*t2); d[n].insert(res);
				}
				if (*t1 != 0) {
					res = *t2 / (*t1); d[n].insert(res);
				}				
			}
		}
		++l; --r;
	}
}
int main() {
	int i, n;
	scanf("%d%d",&K,&n);
	d[0].insert(0);
	d[1].insert(K);
	monod(8);
	while (n--) {
		int a; scanf("%d",&a);
		for (i = 1; i <= 8; ++i) {
			if (d[i].find(a) != d[i].end()) break;
		}
		if (i > 8) puts("NO");
		else printf("%d\n",i);
	}
	return 0;
}