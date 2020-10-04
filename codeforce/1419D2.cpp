//greedy 
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
int a[100001];
int b[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n; cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int ix = 1;
	for (i = 2; i <= n; i += 2) b[i] = a[ix++];
	for (i = 1; i <= n; i += 2) b[i] = a[ix++];
	int cnt =0;
	for (i = 2; i < n; ++i) {
		if (b[i] < b[i - 1] && b[i] < b[i + 1]) ++cnt;
	}
	cout << cnt << "\n";
	for (i = 1; i <= n; ++i) cout << b[i] << " ";
 
	return 0;
}
