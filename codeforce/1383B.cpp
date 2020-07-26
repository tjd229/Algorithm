//game, math
#include <stdio.h>
int o[31],z[31];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (i = 0; i <= 30; ++i) o[i]=0;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			int a; scanf("%d",&a);
			for (int k = 0; a; ++k) {
				o[k] += (a & 1);
				a >>= 1;
			}
		}
		for (i = 0; i <= 30; ++i) z[i] = n - o[i];
		int stat = 0;
		for (i = 30; i >= 0 && stat == 0; --i) {
			if (o[i] & 1) {
				if ((o[i] & 2)&&((z[i]&1)==0)) stat = -1;
				else stat = 1;
			}
		}
		if (stat) printf("%s\n",stat>0? "WIN":"LOSE");
		else printf("DRAW\n");
	}

	return 0;
}