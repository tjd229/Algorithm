//greedy
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, t, n,k;
	cin >> t;
	while (t--) {
		cin >> n>>k>>s;
		vector<pii > ans;
		int stk = 0;
		int cnt = 0;
		for (i = 0; i < n; ++i) {
			if (s[i] == '(') ++stk;
			else --stk;
			if (stk < 0) {
				int r = i;
				for (int j = i; j < n; ++j) {
					if (s[j] == '(') r = j;
				}
				reverse(s.begin() + i, s.begin() + 1 + r);
				ans.push_back({i,r});
				stk = 1;
			}
		}
		for (i = 0; i < n; ++i) {
			if (s[i] == '(') ++stk;
			else --stk;
			cnt += (stk == 0);
		}
		
		//cnt = k;
		if (cnt > k) {
			for (i = 0; i < n && cnt>k; ++i) {
				if (s[i] == '(') ++stk;
				else --stk;
				if (stk == 0) {
					ans.push_back({i,i+1});
					reverse(s.begin() + i, s.begin() + 2 + i);
					--cnt;
					stk = 2;
				}
				
			}
		}
		else if (cnt < k) {
			for (i = 0; i < n-1 && cnt < k; ++i) {
				if (s[i] == '(' && s[i + 1] == '(') {
					int l = i + 1;
					int r = l + 1;
					while (s[r] == '(') ++r;
					ans.push_back({l,r});
					reverse(s.begin() + l, s.begin() + r + 1);
					++cnt;
				}
			}
		}
		//cout << s << endl;
		cout << ans.size() << "\n";
		for (auto p : ans)
			cout << p.first+1 << " " << p.second+1 << "\n";
	}
 
	return 0;
}