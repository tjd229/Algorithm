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
int h[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> h[i];
		sort(h + 1, h + 1 + n);
		int mn = h[n]-h[1];
		int st=1, ed=n;
		for (i = 2; i <= n; ++i) {
			int d = h[i] - h[i - 1];
			if (mn > d) {
				mn = d;
				st = i, ed = i - 1;
			}
		}
		vector<int> ans;
		for (i = st; i <= n; ++i) ans.push_back(h[i]);
		for (i = 1; i <= ed; ++i) ans.push_back(h[i]);
		for (i = 0; i < n;++i) {
			int x = ans[i];
			cout << x << " ";
		}
		cout << "\n";
		
	}
 
 
	return 0;
}