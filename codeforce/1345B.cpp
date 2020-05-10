//math
#include <stdio.h>
#include <algorithm>
using namespace std;
long long num[30001];
int main() {
	int bnd = 30000;
	num[1] = 2;
	for (int i = 2; i <= bnd; ++i) {
		num[i] = num[i - 1] + i * 2 + i - 1;
	}
	int t;
	for (scanf("%d", &t); t--;) {
		int n; scanf("%d",&n);
		int ans = 0;
		if (n >= 2) {
			int mx = lower_bound(num + 1, num + bnd + 1, n)-num;
			
			while (n >= 2 && mx>=1) {
				if (num[mx] <= n) {
					int d = n / num[mx];
					ans += d;
					n -= d * num[mx];
				}
				--mx;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}