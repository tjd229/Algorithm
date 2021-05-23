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
int gcd(int a, int b) {
	if (a == 0) return b;//a<b
	return gcd(b%a, a);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		vector<pii > p1, p2;
		int mn = 2e9;
		int pos = 0;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			if (mn > a[i]) {
				mn = a[i];
				pos = i;
			}
		}
		int y = mn + 1;
		for (i = pos + 1; i <= n; ++i) {
			p1.push_back({pos,i});
			p2.push_back({ mn,y }); ++y;
		}
		y = mn + 1;
		for (i = pos - 1; i > 0; --i) {
			p1.push_back({pos,i});
			p2.push_back({ mn,y }); ++y;
		}
		
		int k = p1.size();
		cout << k << "\n";
		for (i = 0; i < k; ++i) {
			cout << p1[i].first << " " << p1[i].second << " ";
			cout << p2[i].first << " " << p2[i].second << "\n";
		}
	}
 
 
	return 0;
}