//bs, math
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int n;
set<int> L, R;
int diff[10001];
int odd_range(int l, int r) {
	int d = 0;
	int len = r - l + 1;
	for (int i = l; i <= r; ++i) diff[i] = 1;
	printf("? %d %d\n", l, r); fflush(stdout);
	for (int i = 0; i < len; ++i) {
		int a; scanf("%d", &a);
		if (l <= a && a <= r) diff[a] = 0;
		else {
			diff[a] = 1;
			++d;
		}
	}
	return (len - d) & 1;
}
int search(int l, int r) {
	if (l == r) return l;
	int m = (l + r) >> 1;
	int L = m - l + 1;
	int R = r - m + 1;
	int dl = 0, dr = 0;
	
	for (int i = l; i <= m; ++i) dl+= diff[i];
	for (int i = 1 + m; i <= r; ++i) dr+= diff[i];
	if ((L - dl) & 1) {
		if (odd_range(l, m))
			return search(l, m);
		else return search(1 + m, r);
	}
	else {
		if (odd_range(m + 1, r))
			return search(m + 1, r);
		return search(l,m);
	}
 
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i; scanf("%d", &n);
		for (i = 1; i <= n; ++i) diff[i] = 0;
		printf("! %d\n", search(1, n)); fflush(stdout);
	}
	
 
	return 0;
}