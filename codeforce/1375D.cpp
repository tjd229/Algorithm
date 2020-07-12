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
int a[1001],n;
int cnt[1002];
int to[1002];
int tgt[1002];
bool chk() {
	for (int i = 2; i <= n; ++i) {
		if (a[i] < a[i - 1]) return 0;
	}
	return 1;
}
int mex() {
	for (int i = 0; i <= n + 1; ++i) {
		if (cnt[i] == 0) return i;
	}
	return n + 1;
}
void print() {
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int i;
		for (i = 1; i <= n; ++i) cin >> a[i];
		for (i = 0; i <= 1+n; ++i) cnt[i] = 0;
		for (i = 1; i <= n; ++i) cnt[a[i]]++;
		vector<int> ans;
		
		for (i = 1; i <= n; ++i)tgt[i] = i - 1;
		for (i = 1; i <= n; ++i) to[i] = i;
		to[0] = 1;
		int pad = 1;
		while (pad <= n && tgt[pad] == a[pad]) {
			//for (i = pad + 1; i <= n; ++i) ++tgt[i];
			//for (i = 0; i <= n+1; ++i) to[i] = min(to[i] + 1, n);
			to[pad] = pad + 1;
			++pad;
		}
		while (!chk()) {
			int rep = mex();
			int dst = to[rep];
			//cout << rep << endl << dst << endl;
			--cnt[a[dst]];
			++cnt[rep];
			a[dst] = rep;
			while (pad <= n && tgt[pad] == a[pad]) {
				//for (i = pad + 1; i <= n; ++i) ++tgt[i];
				//for (i = 0; i <= n + 1; ++i) to[i] = min(to[i] + 1, n);
				to[pad] = pad+1;
				++pad;
			}
			ans.push_back(dst);
			//print();
			//int y;
			//cin >> y;
		}
		//printf("!\n");
		//print();
		cout << ans.size() << "\n";
		for (auto x : ans) cout << x << " ";
		cout << "\n";
	}
 
	return 0;
}
