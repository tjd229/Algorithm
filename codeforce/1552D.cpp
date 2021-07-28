//graph
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
int a[11];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> a[i];
		for (i = 1; i <= n; ++i) {
			if (a[i] < 0) a[i] = -a[i];
		}
		sort(a + 1, a + 1 + n);
		bool flag = 0;
		for (i = 1; i <= n && flag == 0; ++i)
			if (a[i] == 0) flag = 1;
		for (i = 2; i <= n && flag == 0; ++i)
			if (a[i] - a[i - 1] == 0) flag = 1;
		if (flag == 0) {
			int bnd = 1 << n;
			vector<int> v;
			//for (i = 1; i <= n; ++i) v.push_back(a[i]);
			for (int stat = 1; stat < bnd; ++stat) {
				int c = 0;
				int cnt = 0;
				for (int i = 0; i < n; ++i) {
					if (stat&(1 << i)) c += a[i+1],++cnt;
				}
				v.push_back(c);
			}
			int sz = v.size();
			sort(v.begin(), v.end());
			v.resize(unique(v.begin(), v.end()) - v.begin());
			//printf("%d,%d\n",sz,v.size());
			if (sz != v.size()) flag = 1;
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}