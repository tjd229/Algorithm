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
int a[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> a[i];
		if (a[1] == 1) {
			cout << 1 + n;
			for (i = 1; i <= n; ++i) cout << " " << i;
			cout << "\n";
		}
		else if (a[n] == 0) {
			for (i = 1; i <= n; ++i) cout  << i << " ";
			cout << 1 + n<<"\n";
		}
		else {
 
			int m = 0;
			for (i = 2; i <= n && m == 0; ++i) {
				if (a[i] == 1 && a[i - 1] == 0)
					m = i - 1;
			}
			if (m == 0) cout << "-1\n";
			else {
				for (i = 1; i <= m; ++i) cout << i << " ";
				cout << 1 + n << " ";
				for (i = m + 1; i <= n; ++i) cout << i << " ";
				cout << "\n";
			}
		}
	}
 
 
	return 0;
}
