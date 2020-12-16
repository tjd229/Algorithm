//d&c
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
vector<pair<int, ll> > v;
void dc(int s,int e,set<ll> &st) {
	if (s == e) {
		st.insert(v[s].second);
		return;
	}
	if (s >= e) return;
	//printf("%d,%d\n",s,e);
	ll sum = 0;
	for(int i=s;i<=e;++i)
		sum += v[i].second;
	st.insert(sum);
	int mn = v[s].first, mx = v[e].first;
	int mid = (mn + mx )>> 1;
	int mix = s;
	for (int i = s; i <= e; ++i) {
		if (v[i].first > mid) {
			mix = i;
			break;
		}
	}
	dc(s, mix - 1,st); dc(mix, e,st);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, q; cin >> n >> q;
		map<int, ll> mp;
		set<ll> st;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			mp[a[i]] += a[i];
		}
		v.clear();
		for (auto it : mp) {
			v.push_back(it);
		}
		dc(0, v.size() - 1, st);
		while (q--) {
			int s; cin >> s;
			if (st.find(s) != st.end())
				cout << "YES\n";
			else cout << "NO\n";
		}
	}
 
	return 0;
}