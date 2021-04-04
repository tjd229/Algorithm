//math
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> a[i];
		if (n == 1) {
			cout << "0\n";
			continue;
		}
		int c = a[2] - a[1];
		bool inf = c == 0;
		for (i = 2; i <= n && inf; ++i) {
			if (a[i] != a[i - 1]) inf = 0;
		}
		if (inf) {
			cout << "0\n";
			continue;
		}
		bool flag = 1;
		set<int> neg, pos;
		int mx = a[1];
		for (i = 2; i <= n; ++i) {
			int d = a[i] - a[i - 1];
			if (d < 0) neg.insert(d);
			else if (d > 0) pos.insert(d);
			else flag = 0;
			if (mx < a[i]) mx = a[i];
		}
		if (neg.size() > 1) flag = 0;
		if (pos.size() > 1) flag = 0;
		if (flag == 0) {
			cout << "-1\n";
			continue;
		}
		int m;
		if (neg.size() && pos.size())
			m = -(*neg.begin()) + *pos.begin();
		else if (pos.empty()) {
			cout << "0\n";
			continue;
		}
		else {
			cout << "0\n";
			continue;
		}
		c = *pos.begin();
		//printf("%d,%d,%d\n",c,m,mx);
		if (c >= m || mx >= m) {
			cout << "-1\n";
			continue;
		}
		cout << m << " " << c << "\n";
	}
 
	return 0;
}