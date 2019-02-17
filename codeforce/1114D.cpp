//dp
#include <stdio.h>
#include <memory.h>
int l[5001], r[5001];
int c[5002];
int d[5001][5001][2];
int min(int a, int b) {
	if (b < 0) return a;
	if (a < 0) return b;
	return a < b ? a : b;
}
int color(int s,int e,int dir) {
	if (r[s] > e || l[e] < s) return 0;
	int &pt = d[s][e][dir];
	if (pt != -1) return pt;
	if (dir) {
		int res = color(s, l[e], 1);
		pt = min(pt, res + (c[e] != c[l[e]]));
		res = color(s, l[e], 0);
		pt = min(pt, res + (c[e] != c[s]));
	}
	else {
		int res = color(r[s],e, 1);
		pt = min(pt, res + (c[s] != c[e])); 
		res = color(r[s], e, 0);
		pt = min(pt, res + (c[s] != c[r[s]]));
	}
	
	return pt;
}
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%d",c+i);
		l[i] = l[i - 1];
		if (c[i] != c[i - 1]) l[i]=i-1;
	}
	for (; i--;) {
		r[i] = r[i + 1];
		if (c[i] != c[i + 1]) r[i] = i + 1;
	}
	memset(d, -1, sizeof(d));
	printf("%d",min(color(1,n,0),color(1,n,1)));
	return 0;
}
