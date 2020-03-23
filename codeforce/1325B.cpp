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
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		vector<int> a;
		int n; cin >> n;
		for (int i = 0; i < n; ++i) {
			int e; cin >> e;
			a.push_back(e);
		}
		sort(a.begin(), a.end());
		a.resize(unique(a.begin(), a.end())-a.begin());
		cout << a.size() << "\n";
	}
 
	return 0;
}