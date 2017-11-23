//category : dp, st, lazy propagation

#include <stdio.h>
#include <memory.h>
const int LEAF = 1 << 16;
int st[LEAF + LEAF];
int lazy[LEAF + LEAF];
int d[35001];  //to 1d
int a[35001];
int l[35001];
int last[35001];
int max(int a, int b){ return a < b ? b : a; }
void propagate(int ix){
	if (lazy[ix] != 0){
		st[ix] += lazy[ix];
		if (ix < LEAF){
			lazy[ix + ix] += lazy[ix];
			lazy[1+ix + ix] += lazy[ix];
			//st[ix] = max()
		}
		
		lazy[ix] = 0;
	}
}
void update(int ix,int s,int e,int from,int to,int d_val,int c_val){
	propagate(ix);
	if (e < from || to < s) return;
	if (from <= s&&e <= to){
		if (d_val >= 0) st[ix] = d_val;
		lazy[ix] = c_val;
		propagate(ix);
	}
	else{
		update(ix + ix, s, (s + e) >> 1, from, to, d_val, c_val);
		update(1+ix + ix, 1+( (s + e) >> 1),e, from, to, d_val, c_val);
		st[ix] = max(st[ix + ix], st[ix + ix + 1]);
	}
}
int query(int ix,int s,int e,int from,int to){
	propagate(ix);
	if (e < from || to < s) return 0;
	if (from <= s&&e<=to) return st[ix];
	return max(query(ix + ix, s, ((s + e) >> 1), from, to), query(ix + ix+1, 1+((s + e) >> 1), e,from, to));
}
int main(){
	int i, j;
	int n, k;
	for (scanf("%d%d", &n, &k), i = 1; i <= n; i++){
		scanf("%d",a+i);
		l[i] = last[a[i]];
		last[a[i]] = i;
	}
	
	if (k > 50) k = 50;
	for (i = 1; i <= k; i++){		
		for (j = 1; j <= n; j++){
			update(1,0,LEAF-1,l[j]+1,j,-1,1);
			//update(1, 0, LEAF - 1, j, j, d[i-1][j-1], 0);
			d[j] = query(1,0,LEAF-1,1,j);
		}
		memset(lazy, 0, sizeof(lazy));
		memset(st, 0, sizeof(st));
		for (j = 1; j <=n; j++)
			update(1,0,LEAF-1,j+1,j+1,d[j],0);
	}
	printf("%d",d[n]);


	return 0;
}
