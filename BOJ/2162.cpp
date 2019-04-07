//geometry, ccw, djs
#include <stdio.h>
int p[3001],sz[3001];
int x1[3001], y1[3001], x2[3001], y2[3001];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
bool un(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return 0;
	p[b] = a;
	sz[a] += sz[b];
	return 1;
}
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int t1 = (x2 - x1)*(y3 - y1);
	int t2 = (x3 - x1)*(y2 - y1);
	t1 -= t2;
	if (!t1) return 0;
	return t1 < 0 ? -1 : 1;
}
bool in(int x1, int y1, int x2, int y2, int x3, int y3) {
	if (x1 > x2) x1 ^= x2 ^= x1 ^= x2;
	if (y1 > y2) y1 ^= y2 ^= y1 ^= y2;
	return x1 <= x3 && x3 <= x2 && y1 <= y3 && y3 <= y2;
}
int main() {
	int i, j, N;
	for (scanf("%d", &N), i = 1; i <= N; ++i) {
		scanf("%d%d%d%d",x1+i,y1+i,x2+i,y2+i);
		p[i] = i; sz[i] = 1;
	}
	int ans1 = N, ans2 = 1;
	for (i = 1; i <= N; ++i) {
		for (j = i + 1; j <= N; ++j) {
			int ABC = ccw(x1[i], y1[i], x2[i], y2[i], x1[j], y1[j]);
			int ABD = ccw(x1[i], y1[i], x2[i], y2[i], x2[j], y2[j]);
			int CDA = ccw(x1[j], y1[j], x2[j], y2[j], x1[i], y1[i]);
			int CDB = ccw(x1[j], y1[j], x2[j], y2[j], x2[i], y2[i]);
			bool flag = (ABC != ABD) && (CDA != CDB);
			if (!ABC && !ABD && !CDA && !CDB) {
				flag |= in(x1[i], y1[i], x2[i], y2[i], x1[j], y1[j]);
				flag |= in(x1[i], y1[i], x2[i], y2[i], x2[j], y2[j]);
				flag |= in(x1[j], y1[j], x2[j], y2[j], x1[i], y1[i]);
				flag |= in(x1[j], y1[j], x2[j], y2[j], x2[i], y2[i]);
			}
			if (flag) {
				ans1 -= un(i, j);
				int p = find(i);
				if (ans2 < sz[p]) ans2 = sz[p];
			}
		}
	}
	printf("%d\n%d",ans1,ans2);
	return 0;
}
