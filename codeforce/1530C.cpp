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
int a[100001], b[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		priority_queue<int> q;
		vector<int> stk;
		int me = 0, l = 0;
		int rm = 0;
		for (i = 1; i <= n; ++i) {
			cin >> a[i], me += a[i];
			q.push(-a[i]);
		}
		for (i = 1; i <= n; ++i) cin >> b[i];
		int low = n / 4;
		sort(b + 1, b + 1 + n);
		for (i = 1+low; i <= n; ++i) l += b[i];
		for (i = 1; i < 1 + low; ++i) stk.push_back(b[i]);
		for (i = 0; i < low; ++i) {
			int score = -q.top(); q.pop();
			++rm; me -= score;
		}
		int ans = 0;
		while (me < l) {
			me += 100; q.push(-100);
			++n; low = n / 4;
 
			if (rm < low) {
				int score = -q.top(); q.pop();
				++rm; me -= score;
			}
			else {
				if (stk.size()) {
					l += stk.back();
					stk.pop_back();
				}
			}
			++ans;
		}
		//printf("%d,%d\n",me,l);
		cout << ans << "\n";
	}
 
	return 0;
}