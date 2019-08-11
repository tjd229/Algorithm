//graph, math
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
 
bool solve(int n) {
	int np[1501] = { 0 };
	int deg[1001] = { 0 };
	vector<pii > ans;
	for (int i = 2; i <= 1500; ++i) {
		if (np[i]) continue;	
		for (int j = i * i; j <= 1500; j += i) {
			np[j] = 1;
		}
	}
	for (int i = 1; i < n; ++i) {
		ans.push_back({ i,i + 1 });
		++deg[i]; ++deg[i + 1];
	}
	ans.push_back({ 1,n });
	++deg[n]; ++deg[1];
	int x = 1;
	int m = (n * (n - 1)) >> 1;
	while (np[ans.size()]) {
		if (x + 2 > n) return 0;
		
		while (deg[x] == 3 || deg[x + 2] == 3) {
			++x;
			if (x + 2 > n) return 0;
		}
		
		ans.push_back({ x,x + 2 });
		++deg[x]; ++deg[x + 2];
		++x;
		if (ans.size() > m) return 0;
	}
	/*for (auto p : ans) {
		int x = p.first; int y = p.second;
		if (np[deg[x]]) return 0;
		if (np[deg[y]]) return 0;
	}*/
	
	cout << ans.size() << "\n";
	for (auto p : ans) {
		cout << p.first << " " << p.second << "\n";
	}
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	solve(n);
	//for (int i = 1000; i <= 1000; ++i)
		//if (!solve(i)) printf("!%d\n",i);
	
	return 0;
}