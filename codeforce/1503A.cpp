//greedy
#include <stdio.h>
#include <queue>
using namespace std;
int s[200000];
char a[200001], b[200001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		int sum = 0;
		for (scanf("%d", &n), i = 0; i < n; ++i) {
			scanf("%01d", s + i); sum += s[i];
		}
		if (s[0] == 0 || s[n-1] == 0|| (sum & 1))
			printf("NO\n");
		else {
			int tog = 0;
			int op = n >> 1;
			for (i = 0; i < n; ++i) {
				if (s[i] == 0) {
					if (tog) {
						a[i] = '(', b[i] = ')';
						tog = 1 - tog;
						--op;
					}
					else {
						b[i] = '(', a[i] = ')';
						tog = 1 - tog;
					}
				}
			}
			for (i = 0; i < n; ++i) {
				if (s[i]) {
					if (op) {
						--op;
						a[i] = b[i] = '(';
					}
					else a[i] = b[i] = ')';
				}
			}
			a[n] = b[n] = '\0';
			printf("%s\n%s\n%s\n","YES",a,b);
		}
	}
	return 0;
}
