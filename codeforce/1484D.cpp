//implementation, math
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
int nxt[100001];
int a[100001];
int d[100001];
int gcd(int a, int b) {
	if (a == b) return a;
	if (a > b) a ^= b ^= a ^= b;
	if (a == 0) return b;//a<b
	return gcd(b%a, a);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;  cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> a[i], d[i] = 0;
		for (i = 2; i <= n; ++i) nxt[i - 1] = i;
		nxt[n] = 1; queue<int> q;
		vector<int> ans;
		for (i = 1; i <= n; ++i) q.push(i);
		while (q.size()) {
			int ix = q.front(); q.pop();
			if (d[ix]) continue;
			int com = gcd(a[ix], a[nxt[ix]]);
			if (com == 1) {
				d[nxt[ix]] = 1;
				ans.push_back(nxt[ix]);
				q.push(ix);
				nxt[ix] = nxt[nxt[ix]];
			}
		}
		cout << ans.size();
		for (auto x : ans)
			cout << " " << x;
		cout << "\n";
	}
 
	return 0;
}