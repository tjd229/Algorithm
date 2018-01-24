//category : dp, st, lazy propagation
//reference : http://codeforces.com/contest/115/submission/32740636
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
const int bnd = 2e5;
const int LEAF = 1 << 18;
struct Race{
	int lb, ub;
	int p;
	bool operator<(Race r) const{
		return ub < r.ub;
	}
}race[bnd+1];
int c[bnd + 1];
ll d[bnd + 1];
ll st[LEAF + LEAF];
ll lazy[LEAF+LEAF];

void propagete(int ix){	
	st[ix] += lazy[ix];
	if (ix < LEAF){
		
		lazy[ix + ix] += lazy[ix];
		lazy[ix + ix + 1] += lazy[ix];
	}
	lazy[ix] = 0;
}
void update(int ix, int s, int e, int from, int to,ll val){
	if (lazy[ix] != 0) propagete(ix);
	if (e < from || to < s) return;
	
	if (from <= s&&e <= to){
		lazy[ix] = val;
		propagete(ix);
	}
	else{
		update(ix + ix, s, (s + e) >> 1, from, to, val);
		update(1 + ix + ix, 1 + ((s + e) >> 1), e, from, to, val);
		st[ix] = max(st[ix + ix], st[ix + ix + 1]);
	}
}
ll max_p(int ix, int s, int e, int from, int to){
	if (lazy[ix] != 0) propagete(ix);
	if (e < from || to < s) return 0;
	if (from <= s&&e <= to) return st[ix];
	return max(max_p(ix + ix, s, (s + e) >> 1, from, to),max_p(ix + ix+1,1+((s + e) >> 1),e, from, to));
}
int main(){
	int i,j;
	int n, m;
	ll tot=0;
	ll ans;
	for (scanf("%d%d", &n, &m), i = 1; i <= n; i++)
		scanf("%d",c+i);
	for (i = 1; i <= m; i++)
		scanf("%d%d%d", &race[i].lb, &race[i].ub, &race[i].p);		
	
	sort(race + 1, race + 1 + m);
	for (i = j = 1; i <= n&&j<=m; i++){		
		update(1, 0, LEAF - 1, 1, i, -c[i]);
		while (j<=m&&race[j].ub == i){
			update(1, 0, LEAF - 1, 1, race[j].lb, race[j].p);
			j++;
		}
		d[i] = max(d[i - 1], st[1]);
		update(1, 0, LEAF - 1, i+1, i+1, d[i]);
	}
	printf("%I64d",d[i-1]);
	return 0;
}
