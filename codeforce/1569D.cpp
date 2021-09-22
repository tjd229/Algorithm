//geometry
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
int v[1000001],h[1000001];
int cv[1000001], ch[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		vector<int> X, Y;
		vector<pii > P,P2;
		int i, n, m, k; cin >> n >> m >> k;
		for (i = 0; i < n; ++i) {
			int x; cin >> x;
			X.push_back(x);
			v[x] = 1;
		}
		for (i = 0; i < m; ++i) {
			int y; cin >> y;
			Y.push_back(y); h[y] = 1;
		}
		for (i = 0; i < k; ++i) {
			int x, y; cin >> x >> y;
			P.push_back({x,y});
			P2.push_back({y,x});
		}
		ll ans = 0; int it = 0;
		sort(P.begin(), P.end());
		sort(P2.begin(), P2.end());
		for (auto x : X) {
			vector<int> v;
			while (it < P.size() && P[it].first < x) {
				int y = P[it].second;
				v.push_back(y);
				++it;
			}
			ll cum = v.size();
			//printf("%d:%lld\n",x,cum);
			sort(v.begin(), v.end());
			for (int i = 0; i < v.size();) {
				int j = i; int piv = v[j];
				int cnt = 0;
				while (j < v.size() && piv == v[j]) {
					++j;
					--cum; ++cnt;
				}
				ans += cum * cnt;
				i = j;
			}
			while (it < P.size() && P[it].first == x) ++it;
		}
		it = 0;
		for (auto y : Y) {
			vector<int> v;
			while (it < P2.size() && P2[it].first < y) {
				int x = P2[it].second;
				v.push_back(x);
				++it;
			}
			ll cum = v.size();
			//printf("%d:%lld\n", y, cum);
			sort(v.begin(), v.end());
			for (int i = 0; i < v.size();) {
				int j = i; int piv = v[j];
				int cnt = 0;
				while (j < v.size() && piv == v[j]) {
					++j;
					--cum; ++cnt;
				}
				ans += cum * cnt;
				i = j;
			}
			while (it < P2.size() && P2[it].first == y) ++it;
		}
 
		cout << ans << "\n";
	}
 
	return 0;
}