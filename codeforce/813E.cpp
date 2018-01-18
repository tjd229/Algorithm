//category : pst
//reference : http://codeforces.com/contest/813/submission/32667699

#include <stdio.h>
#include <deque>
using namespace std;
const int LEAF = 1 << 17;
const int BND = 1e5;
int st[BND * 18], l[BND * 18], r[BND * 18];
int root[BND + 1];
int cnt;
deque<int> dq[BND + 1];
int make_tree(int pre,int s,int e,int pos,int val){
	if (pos < s || e < pos) return pre;
	int ix = ++cnt;
	if (s == e){
		st[ix] += val;
	}
	else{
		l[ix] = make_tree(l[pre], s, (s + e) >> 1, pos, val);
		r[ix] = make_tree(r[pre], 1+((s + e) >> 1),e, pos, val);
		st[ix] = st[l[ix]] + st[r[ix]];
	}
	return ix;
}
int query(int ix, int s, int e, int from, int to){
	if (e < from || to < s) return 0;
	if (from <= s&&e <= to) return st[ix];
	return query(l[ix], s, (s + e) >> 1, from, to) + query(r[ix], 1+((s + e) >> 1),e, from, to);
}
int main(){
	int i;
	int ans=0;
	int n, k;
	int a;
	int q, x, y;
	for (scanf("%d%d", &n, &k), i = 1; i <= n; i++){
		scanf("%d",&a);
		dq[a].push_back(i);
		if (dq[a].size()>k){
			x = dq[a].front();
			dq[a].pop_front();
			root[i] = make_tree(root[i-1],0,LEAF-1,x,1);
		}
		else root[i] = root[i - 1];
	}
	for (scanf("%d", &q); q--;){
		scanf("%d%d",&x,&y);
		x = (x + ans) % n + 1;
		y = (y + ans) % n + 1;
		if (x > y) x ^= y ^= x ^= y;
		ans = y - x + 1 - query(root[y],0,LEAF-1,x,y);
		printf("%d\n",ans);
	}

	return 0;
}
