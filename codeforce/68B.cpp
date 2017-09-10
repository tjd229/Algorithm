//category : bs, math
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[10001];
double s[10001];
int main(){
	int i;
	int n, k;
	int mx = 0;
	int mn = 1000;
	int l, r;
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++){
		scanf("%d", a + i);
		if (mx < a[i]) mx = a[i];
		if (mn > a[i]) mn = a[i];
	}
	if (n == 1){
		printf("%f", (double)a[1]);
		return 0;
	}
	sort(a + 1, a + 1 + n);
	for (i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	l = 1;
	r = n;
	int m;
	int nl, nr;
	double x;
	double ans = 0;
	while (l <= r){
		m = (l + r) / 2;
		nl = m;
		nr = n - nl;
		x = ((double)(s[n] - s[m])*(double)nl - (double)(s[m])*(double)nr) / ((double)nl + (double)nr*(double)(1 - k / 100.f));
		if (a[m] <= (double)(s[n] - s[m] - x) / (double)nr){
			if (ans < (double)(s[n] - s[m] - x) / (double)nr){
				if (m == n || (double)a[m + 1] >= (double)(s[n] - s[m] - x) / (double)nr)
					ans = (double)(s[n] - s[m] - x) / (double)nr;
			}

			l = m + 1;
		}
		else r = m - 1;
	}
	printf("%f\n", ans);

	return 0;
}