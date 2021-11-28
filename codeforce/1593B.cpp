//math
#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		ll n; scanf("%I64d",&n);
		if (n % 25 == 0) printf("0\n");
		else {
			int ans = 100;
			vector<int> d;
			while (n) {
				d.push_back(n % 10);
				n /= 10;
			}
			for (int i = 0; i < d.size(); ++i) {
				
				for (int j = 1+i; j < d.size(); ++j) {
					int pick = d[j] * 10 + d[i];
					if (pick % 25 == 0) {
						int cnt = i + j - i - 1;
						if (ans > cnt) ans = cnt;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
 
	return 0;
}