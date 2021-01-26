//math
#include <stdio.h>
#include <map>
using namespace std;
int a[1000001];
int c[1000001];
int decomp(int x) {
	if (c[x] > 0) return c[x];
	int& res = c[x];
	res = 1;
	for (long long i = 2; i*i <= x; ++i) {
		if (x%i == 0) {
			int cnt = 0;
			while (x%i == 0) {
				x /= i;
				++cnt;
			}
			if (cnt & 1) res *= i;
		}
	}
	if (x > 1) res *= x;
	return res;
}
int main() {
	int i, t;
 
	for (i = 1; i <= 1000; ++i)c[i*i] = 1;
 
	for (scanf("%d", &t); t--;) {
		int n;
		int num_sq = 0;
		map<int, int> mp;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			int c = decomp(a[i]);
			++mp[c];
		}
		int beauty[2] = { 0 };
		for (i = 1; i <= n; ++i) {
			int adj = mp[c[a[i]]];
			if (beauty[0] < adj) beauty[0] = adj;
		}
		for (i = 1; i <= n; ++i) {
			if (c[a[i]] == 1) continue;
			int &adj = mp[c[a[i]]];
			if (adj > 0 && (adj & 1) == 0) {
				mp[1] += adj;
				adj = 0;
			}
		}
		beauty[1] = mp[1];
		for (i = 1; i <= n; ++i) {
			int adj = mp[c[a[i]]];
			if (beauty[1] < adj) beauty[1] = adj;
		}
		int q;
		for (scanf("%d", &q); q--;) {
			long long w; scanf("%I64d", &w);
			printf("%d\n", beauty[w > 0]);
		}
	}
	return 0;
}