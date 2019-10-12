//greedy
#include <stdio.h>
int p[200010];
int main() {
	int i, q;
	for (scanf("%d", &q); q--;) {
		int h, n;
		for (scanf("%d%d", &h, &n), i = 1; i <= n; ++i)
			scanf("%d",p+i);
		//int _n = n;
		p[n+1] = 0;
		int buy = 0;
		for (i = 1; i <= n;) {
			if (p[i] <= 2) break;
			if (p[i] - p[i + 1] > 1)
				p[i] = p[i + 1] + 1;
			else {//1
				if (p[i] - p[i + 2] == 2) {
					i += 2;
				}
				else {
					++buy;
					p[i + 1] = p[i + 2] + 1;
					++i;
				}
			}
		}
		printf("%d\n",buy);
	}
	return 0;
}