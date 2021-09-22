//math
#include <stdio.h>
#include <vector>
using namespace std;
int n[51];
int comp[100];
int main() {
	int t;
	comp[35] = comp[32] = 1;
	comp[57] = comp[52] = 1;
	comp[25] = comp[27] = 1;
	comp[72] = comp[75] = 1;
	for (scanf("%d", &t); t--;) {
		int i, k;
		int ans1 = -1;
		char ans2[10];
		for (scanf("%d", &k), i = 1; i <= k; ++i) scanf("%1d",n+i);
		for (i = 1; i <= k; ++i) {
			if (n[i] == 1) {
				ans1 = 1;
				ans2[0] = '1'; ans2[1] = '\0';
			}
		}for (i = 1; i <= k; ++i) {
			if (n[i] == 9) {
				ans1 = 1;
				ans2[0] = '9'; ans2[1] = '\0';
			}
		}
		for (i = 1; i <= k; ++i) {
			if (n[i] != 2 && (n[i] & 1) == 0) {
				ans1 = 1;
				ans2[0] = n[i]+'0'; ans2[1] = '\0';
			}
		}
		if (ans1 < 0) {
			int cnt[10] = { 0 };
			for (i = 1; i <= k; ++i) {
				++cnt[n[i]];
			}
			for (i = 1; i <= 9; ++i) {
				if (cnt[i] >= 2) {
					ans1 = 2;
					ans2[0] = ans2[1] = i + '0'; ans2[2] = '\0';
				}
			}
			if (ans1 < 0) {
				for (i = 1; i <= k && ans1<0; ++i) {
					int num = 10 * n[i];
					for (int j = i + 1; j <= k && ans1 < 0; ++j) {
						if (comp[num+n[j]]) {
							ans1 = 2;
							ans2[0] = n[i] + '0';
							ans2[1] = n[j] + '0';
							ans2[2] = '\0';
						}
					}
				}
			}
		}
		printf("%d\n%s\n",ans1,ans2);
	}
 
	return 0;
}
