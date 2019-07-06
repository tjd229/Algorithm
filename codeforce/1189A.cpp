//implementation
#include <stdio.h>
int s[101];
int main() {
	int i, n,k=-1;
	int cut[2] = {0};
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%1d", s + i);
		if (s[i] == 0) --s[i];
		s[i] += s[i - 1];
	}
	cut[0] = n;
	if (s[n]) k = 1;
	else {
		for (i = 1; i <= n; ++i) {//k=2
			if (s[i] && s[i] - s[i - 1]) {
				k = 2;
				cut[1] = i;
				break;
			}
		}
	}
	for (printf("%d\n", k), i = 1; i <= n; ++i) {
		int out = s[i] - s[i - 1];
		if (out < 0) ++out;
		printf("%d",out);
		if (cut[k-1] == i) printf(" "),--k;
	}
	return 0;
}