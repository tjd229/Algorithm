//implementation
#include <stdio.h>
int a[101];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n; 
		int cnt[101] = { 0 };
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			scanf("%d",a+i);
			cnt[a[i]]++;
		}
		int unq = 0;
		for (i = 1; i <= 100; ++i) {
			if (cnt[i] == 1) unq = i;
		}
		for (i = 1; i <= n; ++i) {
			if (unq == a[i]) {
				printf("%d\n",i);
				break;
			}
		}
	}
 
	return 0;
}