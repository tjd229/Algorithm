//math
#include <stdio.h>
int q[2];
int ask(int s, int e,int shift) {
	int i;
	for (printf("?"), i = s; i < e; ++i)
		printf(" %d",i<<shift);
	printf("\n"); fflush(stdout);
	int ans; scanf("%d",&ans);
	return ans;
}
int main() {
	
	q[0] = ask(0, 100, 0);
	q[1] = ask(1, 101, 7);
	int qq = q[0] ^ q[1];
	int a = qq & ((1 << 7) - 1);
	printf("! %d", q[0] ^ a); fflush(stdout);
	return 0;
}