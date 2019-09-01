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
int a[150001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		int mn = 1e9;
		int bad = 0;
		for (int i = n; i > 0; --i) {
			if (a[i] > mn) {
				++bad;
			}
			else if (a[i] < mn) mn = a[i];
		}
		cout << bad << "\n";
	}
 
	return 0;
}