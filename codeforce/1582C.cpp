//string
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
pii p[100000];
pii chk(int len) {
	int l = 0, r = len - 1;
	pii ret = { l,r };
	while (l <= r) {
		if (p[l].first != p[r].first) return { -1,-1 };
		ret = {l,r};
		++l; --r;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; string s; cin >> n >> s;
		int ans = -1;
		for (i = 0; i < 26; ++i) {
			char a = 'a' + i;
			int ix = 0;
			int op = 0;
			for (int j = 0; j < s.size(); ++j) {
				if (s[j] != a) p[ix++] = { s[j],j };
				else ++op;
			}
			if (op == n) {//deg
				ans = 0;
				break;
			}
			pii lr = chk(ix);
			if (lr.first != -1) {
				int l = p[lr.first].second;
				int r = p[lr.second].second;
				//printf("%d,%d\n",l,r);
				++l; --r;
				while (l <= r) {//case a
					if (l == r && s[l] == a) {
						--op;
						break;
					}
					op -= 2; ++l; --r;
				}
				l = p[lr.first].second;
				r = p[lr.second].second;
				int L = lr.first, R = lr.second;
				--L; ++R;
				while (L >= 0 && R < ix) {
					int nxtl = p[L].second;
					int nxtr = p[R].second;
					int cntl = l-nxtl-1, cntr = nxtr-r-1;
					op -= min(cntl, cntr)*2;
					l = nxtl, r = nxtr;
					--L; ++R;
				}
				l = 0, r = n - 1;
				int cntl = 0, cntr = 0;
				while (l < n && s[l] == a)++l,++cntl;
				while (r >= 0 && s[r] == a) --r, ++cntr;
				op -= min(cntl, cntr)*2;
				
 
 
				if (ans<0 || ans>op) ans = op;
				//cout << a << endl;
				//cout << op << endl;
			}
		}
		cout << ans << "\n";
	}
 
 
	return 0;
}