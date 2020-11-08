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
string grid[200];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, j, n; cin >> n;
		for (i = 0; i < n; ++i) cin >> grid[i];
		int src[2] = { grid[0][1],grid[1][0] };
		int dst[2] = { grid[n - 1][n - 2],grid[n - 2][n - 1] };
		if (src[0] == src[1] && dst[0] == dst[1] && src[0] != dst[1])
			cout << "0\n";
		else {
			vector<pii > ans;
			//0011
			if (src[0] == '1') ans.push_back({1,2});
			if (src[1] == '1') ans.push_back({2,1});
			if (dst[0] == '0') ans.push_back({n,n-1});
			if (dst[1] == '0') ans.push_back({n-1,n});
			if (ans.size() > 2) {
				ans.clear();
				if (src[0] == '0') ans.push_back({ 1,2 });
				if (src[1] == '0') ans.push_back({ 2,1 });
				if (dst[0] == '1') ans.push_back({ n,n - 1 });
				if (dst[1] == '1') ans.push_back({ n - 1,n });
			}
			cout << ans.size() << "\n";
			for (auto p : ans)
				cout << p.first << " " << p.second << "\n";
		}
	}
 
	return 0;
}