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
int in[1000001];
int mem[1000001];
int a[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll tot = 0;
	int cnt = 0;
	int day = 1;
	int n; cin >> n;
	vector<int> ans;
	bool flag = 1;
	int last = 0;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n && flag; ++i) {
		if (a[i] > 0) {
			if (in[a[i]]) flag = 0;
			else if (mem[a[i]] == day) flag = 0;
			else {
				in[a[i]] = 1;
				tot += a[i];
				++cnt;
				mem[a[i]] = day;
			}
		}
		else {
			a[i] = -a[i];
			if (!in[a[i]]) flag = 0;
			else {
				in[a[i]] = 0;
				tot -= a[i];
				--cnt;
			}
		}
		if (tot == 0 && cnt == 0) {
			ans.push_back(i-last); ++day;
			last = i;
		}
	}
	if (tot != 0 || cnt != 0) flag = 0;
	if (!flag) cout << -1;
	else {
		cout << ans.size() << "\n";
		for (auto x : ans) cout << x << " ";
	}
 
	return 0;
}
