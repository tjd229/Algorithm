//math
#include <stdio.h>
#define ll long long
int A[51];
ll B[51];
void f(ll n, int m) {
	if (m == 1) {
		B[1] = n * A[1];
		return;
	}
	if (n & 1) {
		B[m] = n * A[m];
		f((1 + n) >> 1, --m);
	}
	else {
		B[m] = (n-2+(1LL<<m))*A[m];
		f(n >> 1, --m);
	}
	
}
int main() {
	int i, m; ll n;
	for (scanf("%lld%d", &n, &m), i = 1; i <= m; ++i) scanf("%d",A+i);
	f(n, m);
	for (i = 1; i <= m; ++i) printf("%lld ",B[i]);

	return 0;
}