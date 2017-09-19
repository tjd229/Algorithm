//category : st, d&c

#include <stdio.h>
const int BI = 1 << 17;
struct Node{
	int ix;
	int val;
};
Node st[BI+BI];
int n;
void init(int ix){
	if (st[ix].ix == 0) return;
	st[ix].ix = 0;
	st[ix].val = 0;
	if (ix < BI){
		init(ix + ix);
		init(ix + ix+1);
	}
}
Node min(Node n1, Node n2){
	if (n1.ix == 0) return n2;
	if (n2.ix == 0) return n1;
	return n1.val < n2.val ? n1 : n2;
}
Node range_min(int ix,int s,int e,int from,int to){
	Node node;
	node.ix = node.val = 0;
	if (to < s || e < from) return node;
	if (s >= from&&to >= e) return st[ix];
	return min(range_min(ix + ix, s, (s + e) >> 1, from, to), range_min(ix + ix + 1, ((s + e) >> 1) + 1, e, from, to));
}
long long max(long long a, long long b){
	return a < b ? b : a;
}
long long ans(int s,int e){
	if (s>e) return 0;
	Node node = range_min(1, 1, BI,s, e);
	long long res = (long long)(e - s + 1)*node.val;
	return max(res, max(ans(s,node.ix-1),ans(node.ix+1,e)));
}
void update(int ix, Node node){
	while (ix != 0){
		st[ix] = min(node, st[ix]);
		ix >>= 1;
	}
}
int main(){
	int i;
	int h;
	while (scanf("%d", &n)){
		if (n == 0) break;
		init(1);
		for (i = 1; i <= n; i++){
			Node node;
			scanf("%d",&h);
			node.ix = i;
			node.val = h;
			update(BI + i - 1, node);
		}
		printf("%lld\n",ans(1,n));
	}

	return 0;
}