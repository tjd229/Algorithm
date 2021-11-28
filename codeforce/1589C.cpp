//greedy
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[101], b[101];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i);
		for (i = 1; i <= n; ++i) scanf("%d",b+i);
		sort(a + 1, a + 1 + n); sort(b + 1, b + 1 + n);
		bool flag = 1;
		for (i = n; i > 0 && flag; --i) {
			if (b[i] == a[i]) continue;
			if (b[i] == a[i] + 1) continue;
			flag = 0;
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
 
	return 0;
}