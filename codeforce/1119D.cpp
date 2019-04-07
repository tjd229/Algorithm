//line sweeping, djs
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,int>
using namespace std;
int p[100001];
ll s[100001];
ll ans[100001];
ll l[100001], r[100001];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void un(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	p[b] = a;
}
int main() {
	int i, n, q;
	vector<ll> uq;
	vector<pll > edge;//len,ix
	vector<pll > qry;//len,ix
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> s[i];
		p[i] = i;
		uq.push_back(s[i]);
	}
	sort(uq.begin(), uq.end());
	uq.resize(unique(uq.begin(),uq.end())-uq.begin());
	int g = uq.size();
	for (i = 1; i < g; ++i) {
		edge.push_back({uq[i]-uq[i-1],i});
	}
	sort(edge.begin(), edge.end());
	cin >> q;
	for (i = 0; i < q; ++i) {
		cin >> l[i] >> r[i];
		qry.push_back({r[i]-l[i]+1,i});
	}
	sort(qry.begin(), qry.end());
	i = 0;
	ll pre = 0;
	for (auto p : qry) {
		ll len = p.first;
		int q_ix = p.second;
		while (i < edge.size() && edge[i].first <= len) {//chk
			un(edge[i].second-1,edge[i].second);
			pre += edge[i].first;
			g--;
			++i;
		}
		ans[q_ix] = pre + g * len;
	}
	for (i = 0; i < q; ++i) cout << ans[i]<<" ";
	return 0;
}
