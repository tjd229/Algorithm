//math
#include <stdio.h>
int n;
int q0j[5000], qi0[5000];
int p[5000],b[5000];
int ans[5000];
int cnt;
int ask(int i, int j) {
	printf("? %d %d\n", i, j); fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

int main() {
	int i;
	for (scanf("%d", &n), i = 0; i < n; ++i) q0j[i] = ask(0, i);
	for (qi0[0] = q0j[0], i = 1; i < n; ++i) qi0[i] = ask(i, 0);
	for (int &b0=b[0]= 0; b0 < n; ++b0) {
		//int chk[5000] = { 0 };
		p[0] = b0 ^ qi0[0];
		if (p[0] >= n) continue;
		for (i = 1; i < n; ++i) {
			p[i] = qi0[i] ^ b0;
			b[i] = q0j[i] ^ p[0];
			if (p[i] >= n || b[i]>=n) break;
			//if (chk[p[i]]++) break;
		}
		if (i != n) continue;
		for (i = 0; i < n && p[b[i]] == i; ++i);
		if (i == n) {
			for (i = 0; i < n && cnt==0; ++i) ans[i] = p[i];
			++cnt;
		}
	}
	printf("!\n%d\n",cnt);
	for (i = 0; i < n; ++i) printf("%d ",ans[i]);
	fflush(stdout);
	return 0;
}
