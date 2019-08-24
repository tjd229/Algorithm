//bs, graph
#include "cycle.h"
void escape(int n) {
	int half = n >> 1;
	int prev = 0;
	if (jump(0)) {
		int l = 1, r = half;
		int to0 = -1;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (jump((n - prev + m) % n)) {
				to0 = m;
				l = m + 1;
			}
			else r = m - 1;
			prev = m;
		}
		jump((n-prev+to0)%n);
	}
	else {
		int l = 1, r = half;
		int toM = 1;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (jump((n - prev + m) % n)) r = m - 1;
			else {
				toM = m + 1;
				l = m + 1;
			}
			prev = m;
		}
		jump((n - prev + toM+half) % n);
	}
}
