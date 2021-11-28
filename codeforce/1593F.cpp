//dp
#include <stdio.h>
#include <memory.h>
struct Graph {
	int r, modA, modB;
}bk[41][41][41][41];
int d[41][41][41][41];//step,r,
int x[41];
char s[41];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		memset(d, 0, sizeof(d));
		int i, n, A, B;
		for (scanf("%d%d%d", &n, &A, &B), i = 1; i <= n; ++i) scanf("%1d",x+i);
		d[1][1][x[1] % A][0] = 1;
		d[1][0][0][x[1]%B] = 1;
		for (i = 1; i < n; ++i) {
			for (int r = 0; r <= i; ++r) {
				for (int modA = 0; modA < A; ++modA) {
					for (int modB = 0; modB < B; ++modB) {
						if (d[i][r][modA][modB]) {
							int red = modA * 10 + x[1 + i];
							red %= A;
							d[1 + i][r + 1][red][modB] = 1;
							bk[1 + i][r + 1][red][modB] = { r,modA,modB };
							int blue = modB * 10 + x[1 + i]; blue %= B;
							d[1 + i][r][modA][blue] = 1;
							bk[1 + i][r][modA][blue] = { r,modA,modB };
						}
					}
				}
			}
		}
		int dist = 100;
		int dst_r;
		for (int r = 1; r < n; ++r) {
			if (d[n][r][0][0]) {
				int b = n - r;
				int d = b - r;
				if (d < 0) d = -d;
				if (dist > d) {
					dist = d;
					dst_r = r;
				}
			}
		}
		if (dist == 100) printf("-1\n");
		else {
			int step = n;
			int r= dst_r, modA=0, modB=0;
			s[n] = '\0';
			while (step) {
				Graph &g = bk[step][r][modA][modB];
				--step;
				if (r != g.r) s[step] = 'R';
				else s[step] = 'B';
				r = g.r, modA = g.modA, modB = g.modB;
			}
			printf("%s\n",s);
		}
	}
	return 0;
}