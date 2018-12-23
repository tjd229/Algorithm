//djs

#include <stdio.h>
int N, L, R;
int nation[52][52];
int p[55 * 55];
int deno[55 * 55], nume[55 * 55];
inline int to1d(int x, int y) {
	return x + y * N;
}
int find(int a) {
	if (p[a] != a) return p[a] = find(p[a]);
	return p[a];
}
void un(int a,int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}
int main() {
	int i, j;
	int ix1 = 0;
	for (scanf("%d%d%d", &N, &L, &R), i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j,++ix1) {
			scanf("%d",nation[i]+j);
			p[ix1] = ix1;
		}
	}
	int ans = 0;
	bool flag = true;
	while (flag) {
		flag = 0;
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				if (j < N-1) {
					int d = nation[i][j] - nation[i][j + 1];
					if (d < 0) d = -d;
					if (d >= L && d <= R) un(to1d(j, i), to1d(j + 1, i));
				}
				if (i < N - 1) {
					int d = nation[i][j] - nation[i+1][j];
					if (d < 0) d = -d;
					if (d >= L && d <= R) un(to1d(j, i), to1d(j, i+1));
				}
			}
		}
		for (i = ix1 = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				int p = find(ix1++);
				nume[p] += nation[i][j];
				++deno[p];
			}
		}
		for (i = ix1 = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				int p = find(ix1++);
				nation[i][j] = nume[p] / deno[p];
			}
		}
		for (i = ix1 = 0; i < N; ++i) {//init
			for (j = 0; j < N; ++j,++ix1) {
				if (deno[ix1] > 1)  flag = 1;
				p[ix1] = ix1;
				nume[ix1] = deno[ix1] = 0;
			}
		}
		ans += flag;
	}
	printf("%d",ans);
	return 0;
}
