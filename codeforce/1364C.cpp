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
int a[100001];
int ans[100001];
deque<int> tgt[100001];
bool chk(int n) {
	set<int> st;
	for (int i = 0; i <= n+1; ++i) st.insert(i);
	for (int i = 1; i <= n; ++i) {
		auto it = st.find(ans[i]);
		if (it != st.end())
			st.erase(it);
		if (*st.begin() != a[i]) return 0;
 
	}
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	set<int> st;
	for (int i = 0; i <= 110000; ++i) st.insert(i);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	if (a[1] > 1) cout << -1;
	else {
		/*if (a[1] == 1) {
			tgt[1].push_back(0);
			st.erase(0);
		}
		else {
			tgt[1].push_back(1);
			st.erase(1);
		}*/
		for (int i = 1; i <= n; ++i) {
			if(a[i]==a[i-1]) continue;
			while (*st.begin() != a[i]) {
				int pick = *st.begin();
				tgt[i].push_back(pick);
				st.erase(pick);
				//cout << i << ":" << pick << "\n";
			}
		}
		int r = n;
		bool flag = 1;
		set<int> g;
		for (int i = n; i > 0 && flag; --i) {
			while (tgt[i].size()) {
				g.insert(tgt[i].front());
				tgt[i].pop_front();
			}
			if (g.empty()) ans[i] = a[n] + 1;
			else {
				auto fr = g.begin();
				ans[i] = *fr;
				g.erase(fr);
			}
		}
		//
		if (chk(n) == 0) cout << -1;
		else if (flag) {
			for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
		}
		else cout << -1;
	}
 
	return 0;
}
