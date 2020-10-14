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
int a[51], b[51];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		int s = 0;
		for (i = 1; i <= n; ++i) cin >> a[i],s+=a[i];
		for (i = 1; i <= n; ++i) b[i] = a[i];
		if (s == 0) {
			cout << "NO\n";
			continue;
		}
 
		cout << "YES\n";
		if (s > 0) {
			for (i = 1; i <= n; ++i) {
				if(b[i]>0)
					cout << b[i] << " ";
			}
			for (i = 1; i <= n; ++i) {
				if (b[i] <= 0)
					cout << b[i] << " ";
			}
		}
		else {
			for (i = 1; i <= n; ++i) {
				if (b[i] < 0)
					cout << b[i] << " ";
			}
			for (i = 1; i <= n; ++i) {
				if (b[i] >= 0)
					cout << b[i] << " ";
			}
		}
		
		cout << "\n";
	}
 
	return 0;
}