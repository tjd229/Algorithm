//game
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
int a[200001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i);
		sort(a + 1, a + 1 + n);
		ll Alice = 0, Bob = 0;
		for (i = n; i > 0; i -= 2) {
			if ((a[i] & 1) == 0) Alice += a[i];
			if (i > 1 && (a[i - 1] & 1))Bob += a[i - 1];
		}
		if (Alice > Bob) printf("Alice\n");
		else if (Alice < Bob) printf("Bob\n");
		else printf("Tie\n");
	}
 
	return 0;
}