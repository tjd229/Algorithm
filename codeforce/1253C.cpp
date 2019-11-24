//dp, math
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[200001];
ll s[200001];
ll x[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n, m; cin >> n >> m;
	for (i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	for (i = 1; i <= m; ++i) x[i] = s[i];
	for (i = m + 1; i <= n; ++i) x[i] = s[i] + x[i - m];
	for (i = 1; i <= n; ++i) cout << x[i] << " ";
 
	return 0;
}
