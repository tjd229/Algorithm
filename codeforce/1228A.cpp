//implementation
#include <stdio.h>
bool chk(int x) {
	int stat = 0;
	while (x) {
		int d = x % 10;
		if (stat&(1 << d)) return 0;
		stat += (1 << d);
		x /= 10;
	}
	return 1;
}
int main() {
	int l, r; scanf("%d%d",&l,&r);
	for (int x = l; x <= r; ++x) {
		if (chk(x)) {
			printf("%d",x);
			return 0;
		}
	}
	printf("-1");
	return 0;
}