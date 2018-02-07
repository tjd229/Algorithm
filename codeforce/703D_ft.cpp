//category : ft
//idea reference : http://codeforces.com/contest/703/submission/33659919

#include <stdio.h>
#include <map>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
const int LEAF = 1 << 20;
int ft[LEAF+1];
int ex[1000001];
int a[1000001];
int ans[1000000];
struct Query{
	int l, r, ix;
}q[1000000];
void update(int ix, int x){
	while (ix <= LEAF){
		ft[ix] ^= x;
		ix += (ix&-ix);
	}
}
int query(int ix){
	int res = 0;
	while (ix != 0){
		res ^= ft[ix];
		ix -= (ix&-ix);
	}
	return res;
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
		return q1.l < q2.l;
	});
	for (i = m - 1, j = n; i >= 0; i--){
		while (q[i].l <= j){
			auto pt = mp.find(a[j]);
			if (pt != mp.end()){
				update(pt->second, a[j]);
			}
			mp[a[j]] = j;
			update(j, a[j]);
			j--;
		}
		ans[q[i].ix] = query(q[i].r) ^ ex[q[i].r] ^ ex[q[i].l - 1];
	}
	for (i = 0; i < m; i++) printf("%d\n",ans[i]);

	return 0;
}
