//implementation

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
int a[101], b[101];
int on[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n; string s;
	int mx = 0; int now;
	cin >> n >> s;
	priority_queue<pii > q;
	for (i = 1; i <= n; ++i) cin >> a[i] >> b[i];
	for (i = 1; i <= n; ++i) {
		on[i] = s[i-1] - '0';
		mx += on[i];
		q.push({-b[i],i});
	}
	now = mx;
	while (1) {
		int top = q.top().first;
		if (top < -10000) break;
		while (q.size() && top == q.top().first) {
			int ix = q.top().second;
			int t = -top;
			q.pop();
			if (on[ix]) --now;
			else ++now;
			on[ix] ^= 1;
			q.push({-(t+a[ix]),ix});
		}
		if (mx < now) mx = now;
		//if (now == 3) cout << top << endl;
	}
	cout << mx;
	return 0;
}