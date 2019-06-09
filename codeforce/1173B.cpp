//math, greedy
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int r[1001], c[1001];
int main() {
	int n, m, i, j; cin >> n;
	int pad = 1;
	if (n & 1) pad = 0;
	m = (n+1+pad) >> 1;
	
	for (i = 1; i <= m; ++i) {
		r[i] = 1;
		c[i] = i;
	}
	for (i = m + 1; i <= n; ++i) {
		c[i] = i - m+1;
		r[i] = m;
	}
	cout << m << "\n";
	for (i = 1; i <= n; ++i)
		cout << r[i] << " " << c[i] << "\n";
	/*for (i = 1; i <= n; ++i) {
		for (j = i + 1; j <= n; ++j) {
			int ix_d = j - i;
			int dr = r[j] - r[i];
			int dc = c[j] - c[i];
			if (dr < 0) dr = -dr;
			if (dc < 0) dc = -dc;
			if (dc + dr < ix_d) printf("%d, %d\n",i,j);
		}
	}*/
	return 0;
}