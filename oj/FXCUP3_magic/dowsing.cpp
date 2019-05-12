//implementation
#include "dowsing.h"

void FindTreasure(int N) {
	int i, j;
	int x[2];
	int f = 0;
	for (i = 1; i <= N && f<2; ++i) {
		if (Detect(i, i)) x[f++] = i;
	}
	int xo = 1;
	if (!f) {
		for (i = 1; i < N - 1 && f < 2; i += 2) {
			if (Detect(i + 1, i)) {
				x[f++] = i;
				x[f++] = 1 + i;
			}
		}
		if (!f) x[1] = N, x[0] = N - 1;
		xo = 0;
	}
	int y = 1;
	if (y == x[0]) ++y;
	if (y == x[1]) ++y;
	if (Detect(x[0], y)) {
		Report(x[0], x[0^xo]);
		return;
	}
	Report(x[1], x[1^xo]);
}
