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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		string row1, row2; cin >> row1 >> row2;
		
			bool flag = 1;
			for (i = 1; i < n - 1 && flag; ++i) {
				if (row1[i] == '1' && row2[i] == '1') flag = 0;
			}
			if (flag) cout << "YES\n";
			else cout << "NO\n";
		
	}
 
	return 0;
}