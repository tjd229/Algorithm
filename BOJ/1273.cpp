//category : st
#include <stdio.h>
#define ll long long

const int LEAF = 1 << 22;
ll tower[LEAF+LEAF], hist[LEAF+LEAF];
int can[300001][4];
int pt[4] = { 0, 1, 2, 5 };
void update(int ix,int val, ll st[LEAF+LEAF]){
	while (ix != 0){
		st[ix] += val;
		ix >>= 1;
	}
}
ll sum(int ix,int s,int e,int from,int to,ll st[LEAF+LEAF]){
	if (to < s || e < from) return 0;
	if (s >= from&&to >= e) return st[ix];
	return sum(ix + ix, s, (s + e) >> 1, from, to, st) + sum(ix + ix+1,1+((s + e) >> 1),e, from, to, st);
}
int kth(int ix,int k,ll st[LEAF+LEAF]){
	if (ix >= LEAF) return ix-LEAF;
	return st[ix+ix] >= k ? kth(ix + ix, k,st) : kth(ix + ix + 1, k - st[ix+ix],st);
}
int main(){
	int i,j;
	int N,M;
	int shot;
	int h = 0;
	for (scanf("%d", &N),i=1; i<=3; i++){
		for (j = 1; j <= N; j++) scanf("%d",&can[j][i]);
	}
	for (j = 1; j <= N; j++){
		for (i = 1; i <= 3; i++){
			update(can[j][i - 1] + 1+LEAF, pt[i], tower);
			can[j][i] += can[j][i - 1];
			update(can[j][i] + 1+LEAF, -pt[i], tower);			
		}
		if (h < can[j][3]) h = can[j][3];
	}
	for (i = 1; i <= h; i++) update(LEAF+i,1,hist);
	for (scanf("%d", &M); M--;){
		scanf("%d",&shot);
		shot = kth(1, shot, hist);
		printf("%lld\n", sum(1, 0, LEAF - 1, 0, shot,tower));
		update(LEAF + shot, -1, hist);
	}
	return 0;
}