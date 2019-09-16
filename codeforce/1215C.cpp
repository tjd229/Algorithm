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
string s, t;
int n;
vector<pii > ans;
vector<int> sa, sb;//ab ba
int diff[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s >> t;
	for (int i = 0; i < n; ++i) {
		if (s[i] != t[i]) {
			diff[i] = 1;
			if (s[i] == 'a') sa.push_back(i);
			else sb.push_back(i);
		}
	}
	
	while (sa.size() > 1) {
		int top1 = sa.back(); sa.pop_back();
		int top2 = sa.back(); sa.pop_back();
		ans.push_back({top1+1,top2+1});
	}
	while (sb.size() > 1) {
		int top1 = sb.back(); sb.pop_back();
		int top2 = sb.back(); sb.pop_back();
		ans.push_back({ top1 + 1,top2 + 1 });
	}
	if (sa.size() != sb.size()) cout << -1;
	else {
		//1 vs 1 or 0 0
		if (sa.size()) {
			int top1 = sa[0]+1;
			int top2 = sb[0] + 1;
			ans.push_back({top1,top1});
			ans.push_back({top1,top2});
		}
		cout << ans.size() << "\n";
		for (auto p : ans) {
			int pos1 = p.first;
			int pos2 = p.second;
			cout << pos1 << " " << pos2 << "\n";
		}
	}
 
	return 0;
}