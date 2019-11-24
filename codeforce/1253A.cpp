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
int a[100001], b[100001];
int d[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 1; i <= n; ++i) cin >> b[i];
		for (int i = 1; i <= n; ++i) d[i] = b[i] - a[i];
		bool flag = 1;
		for (int i = 1; i <= n && flag; ++i) {
			if (d[i] < 0) flag = 0;
			else if(d[i]>0){
				int diff = d[i];
				for (int j = i; j <= n && flag; ++j,++i) {
					if (d[j] < 0) flag = 0;
					else if (d[j] == 0) diff = 0;
					else if (d[j] != diff) //d[j]>0
						flag = 0;
				}
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}
