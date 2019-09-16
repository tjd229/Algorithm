//implementation
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
int a[101];
int use[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n; cin >> n;
	int ans = 0;
	for (i = 1; i <= n; ++i) cin >> a[i];
	sort(a+1, a+1 + n);
	for (i = 1; i <= n; ++i) {
		if (use[i]) continue;
		++ans;
		use[i] = 1;
		for (int j = i + 1; j <= n; ++j) {
			if (a[j] % a[i] == 0) use[j]=1;
		}
	}
	cout << ans;
	return 0;
}