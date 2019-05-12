//math, bs
#include "ant.h"
int FindK() {
	int l = 1, r = 1e8; --r;
	int K = 0;
	int m = (r / 3) << 1;
	int cnt = DeliverCount(m);
	if (cnt) {
		l = m / (1 + cnt);
		if (!l) ++l;
		r = m / ( cnt);
	}
	else l = m + 1;
	
	while (l <= r) {
		m = (l + r) >> 1;
		if (DeliverCount(m)) r = m - 1;
		else l = m + 1;
	}
	return r+1;
}