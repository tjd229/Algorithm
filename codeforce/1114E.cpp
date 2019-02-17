//bs, math
#include <stdio.h>
#include <time.h>
#include <random>
#include <set>
using namespace std;
int a[1000001];
int x[60];
int gcd(int a, int b) {
	if (a > b) a ^= b ^= a ^= b;
	if (a == 0) return b;
	return gcd(b%a, a);
}
int main() {
	int i, n;
	scanf("%d",&n);
	if (n <= 60) {
		int x1 = 2e9;
		int x2 = 2e9;
		for (i = 1; i <= n; ++i) {
			printf("? %d\n", i); fflush(stdout);
			scanf("%d",a+i);
			if (a[i] < x1) x1 = a[i];
		}
		for (i = 1; i <= n; ++i) {
			if (a[i] == x1) continue;
			if (a[i] < x2) x2 = a[i];
		}
		printf("! %d %d",x1,x2-x1); fflush(stdout);
	}
	else {
		srand(time(NULL));
		int res;
		int coin = 60;
		int l = 0;
		int r = 1e9;
		int xn = 2e9;
		while (l <= r) {
			int m = (l + r) >> 1;
			printf("> %d\n", m); fflush(stdout);
			--coin;
			scanf("%d",&res);
			if (res) xn = m, l = m + 1;
			else r = m - 1;
		}
		++xn;
		res = 0;
		a[0] = 1;
		for (i = 0; i < coin && i<n; ++i) {
			while(a[res])
				res = ((long long)rand()*rand()%n) + 1;
			a[res] = 1;
			printf("? %d\n", res); fflush(stdout);
			scanf("%d",x+i);
		}
		x[i] = xn;
		set<int> diff;
		for (i = 0; i <= coin && i<=n; ++i) {
			for (int j = i + 1; j <= coin && j<=n; ++j) {
				int d = x[j] - x[i];
				if (d == 0) continue;
				else if (d < 0) d = -d;
				diff.insert(d);
			}
		}
		int d=0;
		for (auto it = diff.begin(); it != diff.end(); ++it)
			d = gcd(d, *it);
		int x1 = xn - (n - 1)*d;
		printf("! %d %d", x1, d); fflush(stdout);
	}
	return 0;
}
