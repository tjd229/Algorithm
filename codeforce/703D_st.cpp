//category : st

#include <stdio.h>
#include <map>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
const int LEAF = 1 << 20;
int st[LEAF + LEAF];
int ex[1000001];
int a[1000001];
int ans[1000000];
struct Query{
	int l, r, ix;
}q[1000000];
void update(int ix, int x){
	st[ix] ^= x;
	ix >>= 1;
	while (ix != 0){
		st[ix] ^= x;
		ix >>= 1;
	}
}
int query(int ix, int s, int e, int from, int to){
	if (e < from || to < s) return 0;
	if (from <= s&&e <= to) return st[ix];
	return query(ix + ix, s, (s + e) >> 1, from, to) ^ query(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to);
}
int main(){
	int i,j;
	int n;
	int m;
	map<int,int > mp;
	for (scanf("%d", &n), i = 1; i <= n; i++){
		scanf("%d",a+i);
		ex[i] = ex[i - 1] ^a[i];
	}
	for (scanf("%d", &m), i = 0; i < m; i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].ix = i;
	}
	sort(q, q + m, [](const Query &q1, const Query &q2){
		return q1.r < q2.r;
	});
	for (i=0,j=1; i < m; i++){
		while (j <= q[i].r){
			auto pt = mp.find(a[j]);
			if (pt != mp.end()){
				update(LEAF+pt->second,a[j]);
			}
			mp[a[j]] = j;
			update(LEAF+j,a[j]);
			j++;
		}
		ans[q[i].ix] = query(1,0,LEAF-1,q[i].l,q[i].r)^ex[q[i].r]^ex[q[i].l-1];
	}
	for (i = 0; i < m; i++) printf("%d\n",ans[i]);

	return 0;
}
