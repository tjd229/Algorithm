//math
#include <stdio.h>
using namespace std;
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int n, m; scanf("%d%d",&n,&m);
 
		if (n == 0) printf("%d\n",1+m);
		else if (m == 0) printf("0\n");
		else if (n > m) printf("0\n");
		else if (n == m) {
			int s = 0;
			while (1) {
				if ((n & 1) == 0) {
					printf("%d\n",1<<s);
					break;
				}
				n >>= 1;
				++s;
			}
		}
		else {
			++m;
			int ans = 0;
			for (int k = 30; k >= 0; --k) {
				int mask = 1 << k;
				if ((n&mask) && (m&mask) == 0)break;
				if ((m&mask) && (n&mask) == 0) ans += mask;
			}
			printf("%d\n",ans);
		}
 
	}
 
	return 0;
}