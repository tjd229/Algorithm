//game, line sweeping
#include <stdio.h>
int side[100001];
int s[2][100001];
int n, k;
inline int sum(int side,int l, int r) {
	if (--l < 0) l = 0;
	if (r > n) r = n;
	return s[side][r] - s[side][l];
}
int main() {
	int i;
	for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i) {
		scanf("%1d", side + i);
		s[0][i] = s[0][i - 1];
		s[1][i] = s[1][i - 1];
		++s[side[i]][i];
	}
	for (i = 1; i+k-1 <= n; ++i) {
		int r = sum(0,0, i - 1) + sum(0,i + k, n);
		if (r == n - k || r == 0) {
			printf("tokitsukaze");
			return 0;
		}
		
	}
	if (n > k + k) {
		printf("once again");
		return 0;
	}
	for (i = 2; i + k - 1 < n; ++i) {
		bool l = sum(0, 0, i - 1) &sum(1, 0, i - 1);
		bool r = sum(0, i+k,n) &sum(1, i+k,n);
		//printf("%d:%d,%d\n",i,l,r);
		if (l | r) {
			printf("once again");
			return 0;
		}
 
	}printf("quailty");
	return 0;
}