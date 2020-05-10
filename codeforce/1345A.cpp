//implementation
#include <stdio.h>
 
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int n, m; scanf("%d%d",&n,&m);
		if (n == 1 || m == 1) printf("YES\n");
		else if (n == 2 && m == 2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}