//implementation
#include <stdio.h>
int a[200][200];
int n, m;
bool sort_chk(int r) {
	if (r >= n) return 1;
	for (int i = r; i < n; ++i) {
		int s = 0;
		for (int j = 0; j < m; ++j) s += a[i][j];
		if (s != 0 && s != m) return 0;
	}
	return 1;
}
int main() {
	int i, j;
	int c[200] = { 0 };
	for (scanf("%d%d", &n, &m), i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) scanf("%d",a[i]+j);
	}
	if (n == 1 || m == 1) {
		for (printf("YES\n%d",0), i = 1; i < n; ++i) printf("%d",a[i][0]);
		for (printf("\n"), i = 0; i < m; ++i) printf("%d",a[0][i]);
		return 0;
	}
	else {
		for (i = 0; i < m; ++i) {
			if (!a[0][i]) {
				c[i] = 1;
				for (j = 0; j < n; ++j) a[j][i] = 1 - a[j][i];
			}
		}
		if (sort_chk(0)) {
			for (printf("YES\n"), i = 0; i < n; ++i) printf("%d",a[i][0]);
			for (printf("\n"), i = 0; i < m; ++i) printf("%d",c[i]);
			return 0;
		}
		for (i = 0; i < m; ++i) {
			c[i] = 1 - c[i];
			for (j = 0; j < n; ++j) a[j][i] = 1 - a[j][i];
			
			if (sort_chk(1)) {
				for (printf("YES\n%d",a[0][0]), i = 1; i < n; ++i) printf("%d", !a[i][0]);
				for (printf("\n"), i = 0; i < m; ++i) printf("%d", c[i]);
				return 0;
			}
		}
	}
	for (i = 0; i < n; ++i) {
		int l = 0, r = -1;
		int piv = a[i][0];
		for (j = 1; j < m; ++j) {
			if (piv == a[i][j]) l = j;
			else if (r < 0) r = j;
		}
		if (l < r && sort_chk(i+1)) {
			for (printf("YES\n"), j = 0; j < i; ++j) printf("%d", a[j][0]);
			for (printf("%d", piv), j = i + 1; j < n; ++j) printf("%d", !a[j][0]);
			for (printf("\n"), i = 0; i < m; ++i) printf("%d", c[i]);
			return 0;
		}
		else if (r >= 0) break;
	}
	printf("NO");
	return 0;
}