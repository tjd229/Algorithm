//category : st, lazy propagation

#include <stdio.h>
#define ll long long
const int LEAF = 1 << 17;
const int lg = 20;
int st[LEAF + LEAF][lg];
int lazy[LEAF+LEAF];
void propagate(int ix,int bnd){	
	int b = 0;
	if (ix < LEAF){
		lazy[ix + ix] ^= lazy[ix];
		lazy[ix + ix + 1] ^= lazy[ix];
	}
	while (lazy[ix] != 0){
		if (lazy[ix] & 1) st[ix][b] = bnd - st[ix][b];
		b++;
		lazy[ix] >>= 1;
	}	
}
void update(int ix, int s, int e, int from, int to, int x){
	if (lazy[ix] != 0) propagate(ix,e-s+1);
	if (e < from || to < s) return;
	if (from <= s&&e <= to){
		lazy[ix] ^= x;
		propagate(ix, e - s + 1);
	}
	else{
		update(ix + ix, s, (s + e) >> 1, from, to, x);
		update(1+ix + ix, 1+((s + e) >> 1),e, from, to, x);
		for (int i = 0; i < lg; i++)
			st[ix][i] = st[ix + ix][i] + st[ix + ix + 1][i];
	}
}
ll sum(int ix, int s, int e, int from, int to){
	if (lazy[ix] != 0) propagate(ix, e - s + 1);
	if (e < from || to < s) return 0;
	if (from <= s&&e <= to){
		ll res = 0;
		for (int i = 0; i < lg; i++)
			res += (ll)st[ix][i] * (1 << i);
		return res;
	}
	return sum(ix + ix, s, (s + e) >> 1, from, to) + sum(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to);
}
int main(){
	int i;
	int a;
	int n, m;
	int t,l, r, x;
	for (scanf("%d", &n), i = 1; i <= n; i++){
		scanf("%d",&a);
		update(1,0,LEAF-1,i,i,a);
	}
	for (scanf("%d", &m); m--;){
		scanf("%d%d%d",&t,&l,&r);
		if (t == 1)
			printf("%I64d\n", sum(1,0,LEAF-1,l,r));
		else{
			scanf("%d",&x);
			update(1,0,LEAF-1,l,r,x);
		}
	}
	return 0;
}
