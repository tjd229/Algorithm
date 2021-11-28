//graph, greedy
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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[100001], b[100001], c[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		set<int> leaf,r;
		int i, n, m; cin >> n >> m;
		for (i = 1; i <= n; ++i) r.insert(i);
		for (i = 1; i <= m; ++i) {
			cin >> a[i] >> b[i] >> c[i];
			if (r.find(b[i]) != r.end()) {
				r.erase(b[i]);
				leaf.insert(b[i]);
			}
		}
		for (auto it = leaf.begin(); it != leaf.end(); ++it)
			cout << *it << " " << *r.begin()<<"\n";
		auto it = r.begin(); int last = *it;
		for (++it; it != r.end(); ++it) {
			cout << *it << " " << last<<"\n";
			last = *it;
		}
		cout << "\n";
		
		
	}
 
 
	return 0;
}