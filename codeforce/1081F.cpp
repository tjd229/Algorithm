//math
#include <stdio.h>
#include <random>
int s[301];
int sf[303];
int n, t;
int flip(int l, int r) {
	printf("? %d %d\n", l, r); fflush(stdout);
	int t; scanf("%d",&t);	
	return t;
}
int main() {
	int i;
	int l, r;
	scanf("%d%d",&n,&t);
	if (n == 1) {
		printf("! %d",t); fflush(stdout);
		return 0;
	}
	for (i = n - 1; i > 0; --i) {
		l = r = i;
		if (n & 1) --l;
		if (l < 1) break;
		int wanna = i & 1; int t_;
		int last = t;
		int f[2] = { 0 };
		while (f[wanna] == 0 || f[1 - wanna] == 1) {
			t_=flip(l,r);
			f[(t_-last)&1]^=1;
			last = t_;
		}
		int pred = i - t + sf[i + 2] + sf[i + 2];
		if (t_ != pred) s[i + 1] = 1;
		sf[i + 1] += s[i + 1];
		sf[i] = sf[i + 1];
		while (f[wanna] + f[1 - wanna]) {
			t_ = flip(l, r);
			f[(t_ - last) & 1] ^= 1;
			last = t_;
		}
	}
	r = 1;
	if (n & 1) {
		int f[2] = { 0 };
		l = 2, r = 3; int t_;
		int last = t;
		while (f[0] == 0 || f[1] == 1) {
			t_ = flip(l, r);
			f[(t_ - last) & 1] ^= 1;
			last = t_;
		}
		int pred = n - 1 - t;
		if (t_ != pred) s[1] = 1;
		r = 2;//remain
	}
	s[r] = t - sf[r + 1] - s[1];
	for (printf("! "),i = 1; i <= n; ++i) printf("%d",s[i]);
	fflush(stdout);
	return 0;
}