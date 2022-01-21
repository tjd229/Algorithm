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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int _min(int a,int b) {
	if (a < 0) return b;
	if (b < 0) return a;
	return min(a, b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,t; cin >> t;
 
	while (t--) {
		int n; string a, b; cin >> n >> a >> b;
		if (a == b) cout << "0\n";
		else {
			int cum = 0;
			for (auto c : a) {
				cum += c - '0';
			}
			if (cum == 0) cout << "-1\n";
			else {
				int dcnt[2] = { 0 };
				int scnt[2] = { 0 };
				int same = 0, diff = 0;
				for (i = 0; i < n; ++i) {
					if (a[i] == b[i]) {
						scnt[a[i]-'0']++;
						++same;
					}
					else {
						dcnt[a[i] - '0']++;
						++diff;
					}
				}
				int ans = -1;
				if (same & 1) {
					int need_scnt = (same >> 1) + 1;
					int need_dcnt = same- need_scnt;
					if (scnt[1] >= need_scnt && scnt[0] >= need_dcnt)
						ans = _min(ans, same);
				}
				else {
					/*int need_scnt = (same >> 1);
					int need_dcnt = same - need_scnt;
					if (scnt[1] >= need_scnt && dcnt[0] >= need_dcnt)
						ans = _min(ans, same);*/
				}
 
				if (diff & 1) {
					/*int need_dcnt = (diff >> 1) + 1;
					int need_scnt = diff - need_dcnt;
					if (scnt[0] >= need_scnt && dcnt[1] >= need_dcnt)
						ans = _min(ans, diff);*/
				}
				else {
					int need_dcnt = (diff >> 1) ;
					int need_scnt = diff - need_dcnt;
					if (dcnt[0] >= need_scnt && dcnt[1] >= need_dcnt)
						ans = _min(ans, diff);
				}
				
				cout << ans << "\n";
			}
		}
	}
 
 
	return 0;
}