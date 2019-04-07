//geometry, ccw
#include <stdio.h>
#include <algorithm>
using namespace std;
int assign[11],N;
int sx[11], sy[11], ex[11], ey[11];
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int t1 = (x2 - x1)*(y3 - y1);
	int t2 = (x3 - x1)*(y2 - y1);
	t1 -= t2;
	if (!t1) return 0;
	return t1 < 0 ? -1 : 1;
}
int in(int x1, int y1, int x2, int y2, int x3, int y3) {
	if (x1 > x2) x1 ^= x2 ^= x1 ^= x2;
	if (y1 > y2) y1 ^= y2 ^= y1 ^= y2;
	return x1 <= x3 && x3 <= x2 && y1 <= y3 && y3 <= y2;
}
bool sim() {
	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			int ABC = ccw(sx[i], sy[i], ex[assign[i]], ey[assign[i]], sx[j], sy[j]);
			int ABD = ccw(sx[i], sy[i], ex[assign[i]], ey[assign[i]], ex[assign[j]], ey[assign[j]]);
			int CDA = ccw(sx[j], sy[j], ex[assign[j]], ey[assign[j]], sx[i], sy[i]);
			int CDB = ccw(sx[j], sy[j], ex[assign[j]], ey[assign[j]], ex[assign[i]], ey[assign[i]]);
			bool flag = (ABC != ABD) && (CDA != CDB);
			if (!ABC && !ABD && !CDA && !CDB) {				
				flag|=in(sx[i], sy[i], ex[assign[i]], ey[assign[i]], sx[j], sy[j]);
				flag|=in(sx[i], sy[i], ex[assign[i]], ey[assign[i]], ex[assign[j]], ey[assign[j]]);
				flag|=in(sx[j], sy[j], ex[assign[j]], ey[assign[j]], sx[i], sy[i]);
				flag|=in(sx[j], sy[j], ex[assign[j]], ey[assign[j]], ex[assign[i]], ey[assign[i]]);
			}
			if (flag) return 0;
		}
	}
	return 1;
}
int main() {
	int i;
	for (scanf("%d", &N), i = 1; i <= N; ++i) {
		scanf("%d%d",sx+i,sy+i);
		assign[i] = i;
	}
	for (i = 1; i <= N; ++i) scanf("%d%d",ex+i,ey+i);
	do {
		if (sim()) {
			for (i = 1; i <= N; ++i) printf("%d\n",assign[i]);
			break;
		}
	} while (next_permutation(assign + 1, assign + N+1));
	return 0;
}
