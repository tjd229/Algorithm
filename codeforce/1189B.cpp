//greedy
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100001];
int c[100001];
int main() {
	int l = 1, r;
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i);
	sort(a + 1, a + 1 + n, [](int a, int b) {
		return a > b;
	});
	c[l++] = a[1]; r = n;
	for (i = 2; i <= n; ) {
		c[l++] = a[i++];
		if(i<=n)
			c[r--] = a[i++];
	}
	bool valid = 1;
	valid &= c[1] < c[2] + c[n];
	valid &= c[n] < c[1] + c[n-1];
	for (i = 2; i < n && valid; ++i) {
		valid &= c[i] < c[i-1] + c[1+i];
	}
	printf("%s\n",valid? "YES":"NO");
	for (i = 1; i <= n && valid; ++i) printf("%d ",c[i]);
	return 0;
}