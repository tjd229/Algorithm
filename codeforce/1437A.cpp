//math
#include <stdio.h>
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int l, r; scanf("%d%d",&l,&r);
		printf("%s\n",l+l>r? "YES":"NO");
	}
 
	return 0;
}