//implementation
#include <stdio.h>
#define ll long long
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int n,m; scanf("%d%d",&n,&m);
		int nm = n * m;
		if (nm % 3 == 0) printf("%d\n",nm/3);
		else {
 
			printf("%d\n", nm / 3 + 1);
		}
	}
 
	return 0;
}