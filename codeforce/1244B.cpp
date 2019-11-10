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
string room;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		int ans = 0;
		cin >> room;
		for (i = 0; i < n; ++i) {
			int go = max(n-i,i+1);
			
			if (room[i]=='1') go += go;
			if (ans < go) ans = go;
		}
		cout << ans << "\n";
	}
	
 
	return 0;
}