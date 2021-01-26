//greedy
#include <stdio.h>
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n; scanf("%d", &n);
		int digit = 9;
		if (n < 3) {
			while (n--) printf("%d",digit--);
		}
		else {
			printf("989"); n -= 3;
			digit = 0;
			while (n--) {
				printf("%d",digit++);
				if (digit > 9) digit = 0;
			}
		}
		puts("");
	}
	return 0;
}