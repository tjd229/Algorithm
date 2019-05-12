//implementation
#include <stdio.h>
int mp[1001][1001];
int main() {
	int i, tc, T, A;
	for (scanf("%d",&T), tc = 1; tc <= T; ++tc) {
		int i_=-1, j_=-1;
		for (scanf("%d", &A), i = 2; i_ + j_; i += 3) {
			int dig = 0;
			while (i_+j_ && dig < 9) {
				printf("%d %d\n", i, 2); fflush(stdout);
				scanf("%d%d",&i_,&j_);
				dig += mp[i_][j_] != tc;
				mp[i_][j_] = tc;
			}
		}
	}
	return 0;
}