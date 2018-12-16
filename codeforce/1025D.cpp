//graph, dp

#include <stdio.h>
int a[701];
int d[701][701][2];
int mat[701][701];
int gcd(int a, int b) {
	if (!a) return b;
	return gcd(b%a, a);
}
int recover(int s, int e, int dir) {
	if (s > e) return 1;
	else if (s == e) return dir? mat[s][s-1]:mat[s][e+1];
	int &pt = d[s][e][dir];
	if (pt != -1) return pt;
	pt = 0;
	//
	int p = dir ? s - 1 : e + 1;
	for (int i = s; i <= e && pt==0; ++i) {
		if (mat[p][i]) {
			pt = recover(s, i - 1, 0)&recover(i + 1, e, 1);
		}
	}
	return pt;
}
int main() {
	int i,j;
	int n;
	bool ans = 0;
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i);
	for (i = 1; i < n; ++i) {
		for (j = i + 1; j <= n; ++j) {
			d[i][j][0]=d[i][j][1] = -1;
			int cd = gcd(a[i], a[j]);
			if (cd != 1) {
				mat[i][j] = mat[j][i] = 1;
			}
		}
	}
	for (i = 1; i <= n && !ans; ++i) {
		ans = recover(1, i - 1, 0)&recover(i + 1, n, 1);
	}
	printf("%s",ans? "Yes":"No");
	return 0;
}
