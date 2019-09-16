//dp
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
int d[200001][2]; //0 neg, 1 pos
ll ans[2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n; cin >> n;
	for (i = 1; i <= n; ++i) {
		int a; cin >> a;
		if (a > 0) {
			d[i][0] = d[i - 1][0];
			d[i][1] = d[i - 1][1]+1;
		}
		else {
			d[i][0] = d[i - 1][1] + 1;
			d[i][1] = d[i - 1][0];
		}
	}
	for (i = 1; i <= n; ++i) {
		for (int j = 0; j < 2; ++j) ans[j] += d[i][j];
	}
	cout << ans[0] << " " << ans[1];
	return 0;
}
