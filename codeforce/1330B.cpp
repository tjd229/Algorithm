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
int cnt[200001];
int a[200001];
int show[200001];
bool chk(int s,int e,int stamp) {
	//printf("%d~%d\n",s,e);
	if (s > e) return 0;
	int mx = 0;
	for (int i = s; i <= e; ++i) {
		if (show[a[i]] == stamp) return 0;
		show[a[i]] = stamp;
		if (mx < a[i]) mx = a[i];
	}
	//printf("%d,%d\n",mx,e-s+1);
	return mx == e - s + 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	int stamp = 0;
	while (t--) {
		int n,i;
		cin >> n;
		int mx = 0;
		vector<int > ans;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			if (mx < a[i]) mx = a[i];
			++cnt[a[i]];
		}
		bool flag = 1;
		int d = 0;
		for (i = 1; i <= mx && flag; ++i) { //O(n)
			if (cnt[i] == 1) {
				break;
			}
			else if (cnt[i] > 2) flag = 0;
			else d = i;
		}
		if (d == 0) flag = 0;
		for (i = d + 1; i <= mx && flag; ++i) {
			if (cnt[i] != 1) flag = 0;
		}
		if (flag) {
			int l=-1, r=-1;
			for (i = 1; i <= n; ++i) {
				if (d == a[i]) {
					if (l < 0) l = i;
					else r = i;
				}
				
			}
			if (l>0 && l < d) l = d;
			if (chk(1, l, ++stamp) && chk(1 + l, n, ++stamp))
				ans.push_back(l);
			
			if (r > 0 && r > n - d + 1) r = n - d + 1;
			
			if (chk(1, r - 1, ++stamp) && chk(r, n, ++stamp)) {
				
				if(!(ans.size() && ans[0]==r-1))
					ans.push_back(r - 1);
			}
		}
		
		cout << ans.size() << "\n";
		for (auto l1 : ans) {
			cout << l1 << " " << n-l1 << "\n";
		}
		for (i = 1; i <= mx; ++i) cnt[i] = 0;
	}
 
	return 0;
}