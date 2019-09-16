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
int ans[200001];
//int use[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, t, n;
	cin >> t;
 
	for (int tc = 1; tc <= t; ++tc) {
		int stamp = 1;
		string d; cin >> n >> d;
		int p = 0;
		for (int g = 0; g < 10; ++g) {
			//++stamp;
			vector<int> use(n);
			int last = -1;
 
			int valid = 1;
			vector<int > st[2];
			for (int piv = 0; piv <= g && last < n - 1; ++piv) {
				char cp = piv + '0';
				for (int i = last + 1; i < n; ++i) {
					if (d[i] == cp) {
						st[0].push_back(i);
						last = i;
						use[i] = stamp;
					}
				}
			}
			//int mx = d[st[0].back()];
			last = -1;
 
			for (int piv = g; piv < 10 && last < n - 1 && valid; ++piv) {
				char cp = piv + '0';
				for (int i = last + 1; i < n && valid; ++i) {
					if (use[i] == stamp) continue;
					//cout << (int)(mx - '0') << endl;
					//cout << "!" << piv << endl;
					//cout <<"!" <<i << endl;
					if (d[i] < cp) {
						valid = 0;
						break;
					}
					if (d[i] == cp) {
						st[1].push_back(i);
						last = i;
						use[i] = stamp;
					}
 
				}
			}
			//cout << valid << endl;
			//printf("%d,%d\n",st[0].size(),st[1].size());
			if (st[0].size() + st[1].size() != n) valid = 0;
			if (valid) {
				for (auto x : st[0]) ans[x] = 1;
				for (auto x : st[1]) ans[x] = 2;
				vector<int> order;
				for (i = 0; i < n; ++i) 
					if (ans[i] == 1) order.push_back(d[i]);
				for (i = 0; i < n; ++i)
					if (ans[i] == 2) order.push_back(d[i]);
				int last = 0;
				for (auto x : order) {
					if (last > x) valid = 0;
					last = x;
				}
 
			}
			if (valid) {
				//for (auto x : st[0]) ans[x] = 1;
				//for (auto x : st[1]) ans[x] = 2;
				for (i = 0; i < n; ++i) cout << ans[i];
				cout << "\n";
				p = 1;
				break;
			}
		}
		if (p == 0) cout << "-\n";
	}
 
	return 0;
}