//implementation

#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1000];
int main() {
	int i, n;
	int ans = 0;
	for (scanf("%d", &n), i = 0; i < n; ++i) scanf("%d",a+i);
	sort(a, a + n);
	for (i = 1; i < n; ++i) ans += a[i] - a[i - 1] - 1;
	printf("%d",ans);
	return 0;
}
