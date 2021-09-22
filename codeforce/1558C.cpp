//greedy
#include <stdio.h>
#include <vector>
using namespace std;
int a[2022];
void rev(int p) {
	int l=1, r = p;
	while (l < r) {
		a[l] ^= a[r] ^= a[l] ^= a[r];
		++l; --r;
	}
}
int find(int x) {
	for (int i = 1;; ++i) if (a[i] == x) return i;
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n,m=0;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i);
		for (i = 1; i <= n && m>=0; ++i) {
			if ((i & 1) != (a[i] & 1)) m = -1;
		}
		if (m < 0) {
			printf("-1\n");
			continue;
		}
		vector<int> ans;
		for (i = n; i > 1; i -= 2) {
			if (a[i] != i || i - 1 != a[i - 1]) {
				int p = find(i); rev(p); ans.push_back(p);
				p = find(i - 1);
				if (p != 2) {
					rev(p - 1); ans.push_back(p - 1);
					rev(p + 1); ans.push_back(p + 1);
					rev(3); ans.push_back(3);
				}
				rev(i); ans.push_back(i);
			}
		}
		m = ans.size();
		for (printf("%d\n", m), i = 0; i < m; ++i)
			printf("%d ",ans[i]);
		puts("");
	}
 
	return 0;
}