//math
#include <stdio.h>
#include <algorithm>
using namespace std;
int c[100001], t[100001];
int dc[100001], dt[100001];
int main() {
	int i, n;
	bool flag = 1;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%d",c+i);
		dc[i] = c[i] - c[i - 1];
	}
	for (i = 1; i <= n; ++i) {
		scanf("%d",t+i);
		dt[i] = t[i] - t[i - 1];
	}
	sort(dc + 2, dc +1+ n);
	sort(dt + 2, dt + 1 + n);
	flag = (c[1] == t[1]) && (c[n] == t[n]);
	for (i = 2; i <= n && flag; ++i) {
		flag &= dc[i] == dt[i];
	}
	printf("%s",flag? "Yes":"No");
	return 0;
}
