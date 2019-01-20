//implementation

#include <stdio.h>
int N;
int lx[15];
int rx[15 + 15], ry[15 + 15];
int sim(int y,int stat) {
	if (!stat) return 1;
	int res = 0;
	for (int x = 0; x < N; ++x) {
		if (stat & ((1 << x) == 0)) continue;
		int nx = x - y+N;
		int ny = x + y;
		if (lx[x] || rx[nx] || ry[ny]) continue;
		lx[x] = rx[nx] = ry[ny] = 1;
		res += sim(1 + y, stat - (1 << x));
		lx[x] = rx[nx] = ry[ny] = 0;
	}
	return res;
}
int main() {
	int i, stat = 0;
	for (scanf("%d", &N), i = 0; i < N; ++i) 
		stat += (1 << i);
	printf("%d",sim(0,stat));

	return 0;
}
