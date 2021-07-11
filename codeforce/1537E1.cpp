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
#define ll long long 
#define pii pair<int,int>
using namespace std;
int n, k;
string ans,s;
string op(int r) {
	string base = "";
	for (int i = 0; i < r; ++i) base += s[i];
	string ss = "";
	while (ss.size() < k) ss += base;
	return ss;
}
bool cmp(string &s) {
	for (int i = 0; i < k; ++i) {
		if (ans[i] > s[i]) return 1;
		else if (ans[i] < s[i]) return 0;
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i; cin >> n >> k;
	cin >> s;
	ans = op(1);
	for (i = 2; i <= n; ++i) {
		string ss = op(i);
		if (cmp(ss)) {
			for (int i = 0; i < k; ++i) ans[i] = ss[i];
		}
	}
	cout << ans;
 
	return 0;
}