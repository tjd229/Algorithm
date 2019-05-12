//game
#include <stdio.h>
int a[51];
int main() {
	int i, n;
	int mn = 100;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		if (mn > a[i]) mn = a[i];
	}
	int x=0;
	for (i = 1; i <= n; ++i) x += mn == a[i];
	if (x + x > n) printf("Bob");
	else printf("Alice");

	return 0;
}