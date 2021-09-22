//math
#include <stdio.h>
using namespace std;
int str[20001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		int cum = 0;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%1d",str+i),cum+=str[i];
		int l1, l2, r1, r2;
		int len = n >> 1;
		if (cum == n) {
			l1 = 1, r1 = len;
			l2 = 2, r2 = r1 + 1;
		}
		else {
			int l = 1, r = len;
			for (; r <= n; ++r,++l) {
				if (l > 1 && str[l - 1] == 0) {
					l1 = l, r1 = r;
					r2 = r, l2 = l - 1;
					break;
				}
				if (r < n && str[r + 1] == 0) {
					l2 = l, r2 = r;
					l1 = l, r1 = r + 1;
					break;
				}
			}
		}
		printf("%d %d %d %d\n",l1,r1,l2,r2);
 
	}
	return 0;
}