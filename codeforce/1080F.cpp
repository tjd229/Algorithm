//pst
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int LEAF = 1 << 17;
const int MEM = 1e7;//20*300000
int st[MEM],lc[MEM],rc[MEM];
int root[300002];
int cnt;
//l,r,p(rix,val,xpos)
struct Tuple {
	int x, y, z;
	bool operator<(Tuple &t)const {
		if (x == t.x) {
			if (y == t.y) return z < t.z;
			return y < t.y;
		}
		return x < t.x;
	}
}seg[300000];
int _max(int a, int b) {
	if (!a) return a;
	if (!b) return b;
	return max(a, b);
}
int make_tree(int pre,int s,int e,int pos,int val) {
	if (pos > e || pos < s) return pre;
	int ix = ++cnt;
	if (s == e && s == pos) {
		st[ix] = val;
		if (st[pre] && st[pre] < val) st[ix] = st[pre];
	}
	else {
		int m = (s + e) >> 1;
		lc[ix] = make_tree(lc[pre], s, m, pos, val);
		rc[ix] = make_tree(rc[pre], m + 1, e, pos, val);
		st[ix] = _max(st[lc[ix]], st[rc[ix]]);
	}
	return ix;
}
int rmax(int ix,int s,int e,int from,int to) {
	//if (!ix) return 0;
	if (e < from || to < s) return -1;
	if (!ix) return 0;
	if (from <= s && e <= to) return st[ix];
	
	return _max(rmax(lc[ix],s,(s+e)>>1,from,to),rmax(rc[ix],1+((s+e)>>1),e,from,to));
}
int main() {
	int i, j,n, m, k;
	vector<int> comp;
	for (scanf("%d%d%d", &n, &m, &k), i = 0; i < k; ++i) {
		int l, r, p; scanf("%d%d%d",&l,&r,&p);
		comp.push_back(l);
		seg[i] = {l,r,p};
	}
	sort(seg, seg + k);
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(),comp.end())-comp.begin());

	for (i = j = 0; i < k; ++i) {
		while (comp[j] != seg[i].x) ++j;
		seg[i].x = j;
	}
	int last = root[++j];
	for (i = k - 1; i >= 0; --i) {
		int rix = seg[i].x;
		root[rix] = last = make_tree(last,0,LEAF-1,seg[i].z,seg[i].y);
	}

	while (m--) {
		int a, b, x, y; scanf("%d%d%d%d",&a,&b,&x,&y);
		int rix = lower_bound(comp.begin(), comp.end(), x)-comp.begin();
		if (rix < comp.size()) {
			int res = rmax(root[rix], 0, LEAF - 1, a, b);
			//printf("r:%d\n",res);
			if (res && res <= y) printf("yes\n");
			else printf("no\n");
		}
		else printf("no\n");
		fflush(stdout);
	}
	return 0;
}