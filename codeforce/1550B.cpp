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
string s;
int n, a, b;
int seg(int val) {
	int cnt = 0;
	int last = -1;
	//printf("~\n");
	for (int i = 0; i < n; ++i) {
		if (s[i] == val + '0' && last != s[i]) ++cnt;
		//printf("%d,%d\n", s[i] == val + '0',last != s[i]);
		//printf("%c,%c\n", s[i], val + '0');
		last = s[i];
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i,j; cin >> n >> a >> b>>s;
		int ans = a * n;
		if (b >= 0) ans += b * n;
		else {
			int seg0 = seg(0);
			int seg1 = seg(1);
			int zero_first = seg0 + (seg1 > 0);
			int one_first = seg1 + (seg0 > 0);
			//printf("%d,%d\n", seg0, seg1);
			ans += b * min(zero_first, one_first);
		}
		cout << ans << "\n";
 
	}
 
	return 0;
}