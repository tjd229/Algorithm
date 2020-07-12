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
ll s[2][200001];
int a[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n; cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i & 1) s[1][i] = a[i];
		else s[0][i] = a[i];
		s[1][i] += s[1][i - 1];
		s[0][i] += s[0][i - 1];
	}
	ll ans = s[1][n];
	//cout << ans << endl;
	for (i = 1; i < n; ++i) {
		int b = i & 1;
		ll sum = s[b][i] + (s[1 - b][n]-s[1-b][i]);
		if (ans < sum) ans = sum;
		//cout << sum << endl;
	}
	cout << ans << "\n";
 
	return 0;
}