//geometry
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
int a[300001];
int x[3], y[3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i;
		int top = 0;
		for (i = 0; i < 3; ++i) {
			cin >> x[i] >> y[i];
			top = max(top, y[i]);
		}
		vector<int> mx;
		for (i = 0; i < 3; ++i) {
			if (y[i] == top) mx.push_back(x[i]);
		}
		if (mx.size() == 1) cout << "0\n";
		else {
			int d = mx[0] - mx[1];
			if (d < 0) d = -d;
			cout << d << "\n";
		}
	}
 
 
	return 0;
}