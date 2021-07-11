//string
#include <stdio.h>
char s[500000];
int main() {
	int i, n, k;
	int del_pos = 0;
	int rel = 0;
	for (scanf("%d%d %s", &n, &k, s), i = 0; i < n; ++i) {
		if (s[rel] == s[i]) {
			++rel;
			if (del_pos < rel) rel = 0;
			continue;
		}
		else if (s[rel] < s[i]) break;
		else {
			rel = 0;
			del_pos = i;
		}
	}
	rel = 0;
	while (k--) {
		printf("%c",s[rel++]);
		if (rel > del_pos) rel = 0;
	}
 
	return 0;
}