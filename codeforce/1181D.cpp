//st, line sweeping

#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
#define pli pair<ll,int>
using namespace std;
const int LEAF = 1 << 19;
int st[LEAF + LEAF];
int ans[500000];
int hist[500001];
void upd(int ix, int val) {
	while (ix) {
		st[ix] += val;
		ix >>= 1;
	}
}
int kth(int ix,int k) {
	if (ix >= LEAF) return ix - LEAF;
	if (st[ix + ix] >= k) return kth(ix+ix,k);
	else return kth(1+ix+ix,k-st[ix+ix]);
}
int main() {
	int i,j, n, m, q;
	vector<pli > qry,evt,p;
	for (scanf("%d%d%d", &n, &m, &q), i = 0; i < n; ++i) {
		int a; scanf("%d",&a);
		++hist[a];
	}
	for (i = 0; i < q; ++i) {
		ll k; scanf("%I64d",&k);
		qry.push_back({k,i});
	}
	for (i = 1; i <= m; ++i) 
		p.push_back({hist[i],i});
		
	sort(qry.begin(), qry.end());
	sort(p.begin(), p.end());
	ll last = n;
	int val = n;
	for (i = j = 0;i<m;) {
		while (j < m && p[i].first == p[j].first)++j;
		ll d = (p[i].first - val) * i;
		last += d;
		val = p[i].first;
		for (; i < j; ++i) evt.push_back({last,p[i].second});
	}
	
	i = 0; last = n;
	for (auto x : qry) {
		ll year = x.first;
		int ix = x.second;
		while (i < m && evt[i].first < year) {
			upd(LEAF+evt[i].second,1);
			last = evt[i].first;
			++i;
		}
		int pool = st[1];
		int k = (year - last - 1) % pool;
		ans[ix] = kth(1,k+1);
	}
	for (i = 0; i < q; ++i) printf("%d\n",ans[i]);
	return 0;
}