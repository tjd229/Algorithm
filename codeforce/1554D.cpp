//string
#include <stdio.h>
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n; scanf("%d",&n);
		if (n <= 26) {
			for (i = 0; i < n; ++i) printf("%c",'a'+i);
		}
		else {
			char bc[3] = "bc";
			if (n & 1) n -= 2;
			else {
				--n;
				bc[1] = '\0';
			}
			n >>= 1;
			for (i = 0; i < n; ++i) printf("a");
			++n; printf("%s",bc);
			for (i = 0; i < n; ++i) printf("a");
		}
		puts("");
	}
 
	return 0;
}