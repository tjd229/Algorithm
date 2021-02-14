//dp
#include <stdio.h>
int l[500001], r[500001];
int suf[500001];
int a[500001],d[500002];
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i);
	for (i = 1; i <= n; ++i) r[a[i]] = i;
	for (i = n; i > 0; --i) l[a[i]] = i;
	for (i = n; i > 0; --i) {
		++suf[a[i]];
		d[i] = d[i + 1];
		if (i != l[a[i]] && d[i] < suf[a[i]])
			d[i] = suf[a[i]];
		if (i == l[a[i]] && d[i] < d[r[a[i]]+1]+suf[a[i]])
			d[i] = d[r[a[i]] + 1] + suf[a[i]];
	}
	printf("%d",n-d[1]);
	
	
	return 0;
}
