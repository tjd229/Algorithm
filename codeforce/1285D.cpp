//d&c, math
#include <stdio.h>
#include <vector>
using namespace std;
int dfs(int b,vector<int> &v) {
	if (b == 0) return 0;
	vector<int> on, off;
	for (auto x : v) {
		if (b&x) on.push_back(x);
		else off.push_back(x);
	}
	int res1 = 2e9, res2 = 2e9;
	if(on.size())
		res1 = dfs(b >> 1, on);
	if(off.size())
		res2 = dfs(b >> 1, off);
	if (on.empty() || off.empty()) b = 0;
	return res1 < res2 ? res1 + b : res2 + b;
}
int main() {
	int i, n;
	vector<int> v;
	for (scanf("%d", &n), i = 0; i < n; ++i) {
		int a; scanf("%d",&a);
		v.push_back(a);
	}
	printf("%d", dfs(1 << 29, v));
	return 0;
}