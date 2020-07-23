//greedy
#include <stdio.h>
int a[200001];
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i);
		int it = n;
		int piv = a[n];
		while (it > 0 && a[it] >= piv) 
			piv = a[it--];
		
		//printf("%d\n",it);
		piv = a[++it];
		while (it > 0 && a[it] <= piv) piv=a[it--];
		printf("%d\n",it);
	}
	return 0;
}
