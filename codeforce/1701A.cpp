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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[300001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i; int g = 0;
		for (i = 0; i < 4; ++i) {
			int a; cin >> a;
			g += a;
		}
		if (g == 4) cout << "2\n";
		else if (g == 0) cout << "0\n";
		else cout << "1\n";
	}
 
 
	return 0;
}