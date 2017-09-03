//category : bs, st

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int LEAF = 1 << 17;
vector<int> st[LEAF + LEAF];
void init(int ix,int n){
	while (ix != 0){
		st[ix].push_back(n);
		ix >>= 1;
	}
}
void node_sort(int ix){
	if (ix >= LEAF) return;
	if (st[ix].size() == 0) return;
	sort(st[ix].begin(), st[ix].end());
	node_sort(ix+ix);
	node_sort(ix+ix+1);
}
int query(int ix,int s,int e,int from,int to,int x){
	if (s > to || e < from) return 0;
	if (from <= s&&e <= to) return lower_bound(st[ix].begin(), st[ix].end(), x) - st[ix].begin();
	return query(ix + ix, s, (s + e) >> 1, from, to, x) + query(ix + ix+1,((s + e) >> 1)+1,e, from, to, x);
}
int main(){
	int i,j,k;
	int n, m;
	int a;
	int l, r, mid;
	int min_a = 1000000000;
	int max_a = -1000000000;
	scanf("%d%d",&n,&m);
	for (i = 0; i < n; i++){
		scanf("%d",&a);
		if (min_a > a) min_a = a;
		if (max_a < a) max_a = a;
		init(LEAF + i, a);
	}
	node_sort(1);
	while (m--){
		scanf("%d%d%d",&i,&j,&k);
		l = min_a;
		r = max_a;
		while (l <= r){
			mid = (l + r) >> 1;
			if (query(1, 1, LEAF, i, j, mid) < k){
				a = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		printf("%d\n",a);
	}
	return 0;
}