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
vector<int> inc[300001];
int a[300001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int cnt = 0;
		for (i = 1; i <= n; ++i) cin >> a[i];
		
 
		if (a[1]<a[n]) cout << "YES\n";
		else cout << "NO\n";
		//inc[0].clear();
	}
 
	return 0;
}
