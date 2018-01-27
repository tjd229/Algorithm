//category : st, lazy propagation

#include <stdio.h>
#define ll long long
const int LEAF = 1 << 17;
int st[LEAF + LEAF], nclr[LEAF + LEAF];
ll lazy[LEAF + LEAF], cf[LEAF+LEAF];
void propagate(int ix){
	cf[ix] += lazy[ix];
	lazy[ix] >>= 1;
	st[ix] = nclr[ix];
	if (ix < LEAF){
		lazy[ix + ix] += lazy[ix];
		lazy[1+ix + ix] += lazy[ix];
		nclr[ix + ix] = nclr[ix + ix + 1] = nclr[ix];
	}
	nclr[ix]=lazy[ix] = 0;
}
void update(int ix, int s, int e, int from, int to, int clr){
	if (nclr[ix] != 0) propagate(ix);
	if (e < from || to < s) return;
	if (s >= from&&to >= e&&st[ix]){
		ll d = clr - st[ix];
		if (d < 0) d = -d;
		lazy[ix] += (e - s + 1)*d;
		nclr[ix] = clr;
		propagate(ix);		
	}
	else{
		update(ix + ix, s, (s + e) >> 1, from, to, clr);
		update(1+ix + ix, 1+((s + e) >> 1),e, from, to, clr);
		st[ix] = st[ix + ix] == st[ix + ix + 1] ? st[ix + ix] : 0;
		cf[ix] = cf[ix + ix] + cf[ix + ix + 1];
	}
}
ll sum(int ix, int s, int e, int from, int to){
	if (nclr[ix] != 0) propagate(ix);
	if (e < from || to < s) return 0;
	if (s >= from&&to >= e) return cf[ix];
	return sum(ix + ix, s, (s + e) >> 1, from, to) + sum(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to);
}
int main(){
	int i;
	int n, m;
	int type;
	int l, r, x;
	for (scanf("%d%d", &n, &m), i = 1; i <= n; i++)
		st[LEAF + i] = i;
	while (m--){
		scanf("%d%d%d",&type,&l,&r);
		if (type == 1){
			scanf("%d",&x);
			update(1,0,LEAF-1,l,r,x);
			
		}
		else printf("%I64d\n",sum(1,0,LEAF-1,l,r));
	}

	return 0;
}
