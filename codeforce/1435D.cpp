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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n; cin >> n;
	int nn = n + n;
	vector<int> v,ans;
	int stk = 0;
	bool flag = 1;
	for (i = 1; i <= nn; ++i) {
		char evt; cin >> evt;
		if (evt == '+') v.push_back(-1),++stk;
		else {
			if (stk == 0) flag = 0;
			int p; cin >> p;
			v.push_back(p);
		}
	}
	if (!flag) {
		cout << "NO\n";
		return 0;
	}
	reverse(v.begin(), v.end());
	set<int> st;
	stk = 0;
	for (i = 0; i < v.size() && flag; ++i) {
		int evt = v[i];
		if (evt < 0) ++stk;
		else {
			while (st.size() && stk) {
				auto it = st.begin();
				ans.push_back(*it);
				st.erase(it);
				--stk;
			}
			if (stk > 0) flag = 0;
			else if (st.size() && *st.begin() < evt)
				flag = 0;
			else st.insert(evt);
		}
	}
	while (st.size() && stk) {
		auto it = st.begin();
		ans.push_back(*it);
		st.erase(it);
		--stk;
	}
	if (!flag) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	while (ans.size()) {
		cout << ans.back() << " ";
		ans.pop_back();
	}
 
 
	return 0;
}