//d&c, ft, greedy
#include <stdio.h>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
const int LEAF = 1 << 21;
int a[1000001], b[1000001];
vector<pair<int,int> > c;
int fwinv[1000001], bkinv[1000001];
int ft[LEAF];
void upd(int ix, int val) {
	for (; ix < LEAF; ix += ix&-ix) ft[ix]+=val;
}
int sum(int ix) {
	int res = 0;
	for (; ix > 0; ix -= ix & -ix) res += ft[ix];
	return res;
}
void in(int from,int to,int s,int e) {
	if (s > e) return;
	int m = (s + e) >> 1;
	int piv = b[m];
	for (int i = from; i <= to; ++i) fwinv[i]=bkinv[i] = 0;
	for (int i = from; i <= to; ++i) {
		if (i > from) {
			fwinv[i] = fwinv[i - 1];
			fwinv[i] += a[i] > piv;
		}		
	}
	for (int i = to; i >= from; --i) {
		if (i < to)
			bkinv[i] += bkinv[i + 1];
		if(i>0)
			bkinv[i-1] += piv > a[i];
	}
	int pos = from;
	int inv = fwinv[from] + bkinv[from];
	for (int i = from; i <= to; ++i) {
		
		if (inv > fwinv[i] + bkinv[i]) {
			inv = fwinv[i] + bkinv[i];
			pos = i;
		}
	}
	c.push_back({pos,piv});
	in(from, pos, s, m - 1);
	in(pos, to, 1 + m, e);
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n, m;
		vector<int> A; c.clear();
		for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) {
			scanf("%d", a + i), A.push_back(a[i]);
			c.push_back({i,a[i]});
		}
		for (i = 1; i <= m; ++i) scanf("%d",b+i),A.push_back(b[i]);
		ll ans = 0;
		sort(A.begin(), A.end()); sort(b + 1, b + 1 + m);
		A.resize(unique(A.begin(), A.end()) - A.begin());

		in(0, n, 1, m); sort(c.begin(), c.end()); reverse(c.begin(), c.end());
		//
		for(auto &p:c) {
			int x = p.second;
			//printf("%d ", p.second);
			x=lower_bound(A.begin(), A.end(), x)-A.begin();
			++x;
			p = {0,x};
			ans += sum(x - 1); upd(x, 1);
			
		}
		printf("%I64d\n",ans);
		for (auto p : c) {
			int x = p.second; upd(x, -1);
		}
	}

	return 0;
}