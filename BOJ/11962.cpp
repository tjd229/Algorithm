//category : st, lazy propagation
#include <utility>
#include <stdio.h>
#define ll long long
#define mp make_pair
using namespace std;
const int LEAF = 1 << 18;
ll sum[LEAF + LEAF];
ll minima[LEAF + LEAF];
ll lazy[LEAF + LEAF];
ll min(ll a, ll b){
	if (a < 0) return b;
	if (b < 0) return a;
	return a < b ? a : b;
}
void propagation(int ix,int s,int e){
	if (lazy[ix] != 0){
		sum[ix] += lazy[ix] * (e - s + 1);
		minima[ix] += lazy[ix];
		if (ix < LEAF){
			lazy[ix + ix] += lazy[ix];
			lazy[ix + ix + 1] += lazy[ix];
		}
		lazy[ix] = 0;
	}
}
void update(int ix, int s, int e, int from, int to, int val){
	propagation(ix, s, e);
	if (e < from || to < s) return;
	if (from <= s&&e <= to){
		sum[ix] += (ll)val * (e - s + 1);
		minima[ix] += val;
		if (ix < LEAF){
			lazy[ix + ix] += val;
			lazy[ix + ix + 1] += val;
		}
		return;
	}
	update(ix + ix, s, (s + e) >> 1, from, to, val);
	update(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to, val);
	
		//
	sum[ix] = sum[ix + ix] + sum[ix + ix + 1];
	minima[ix] = min(minima[ix + ix], minima[ix + ix + 1]);
	
}
pair<ll, ll> query(int ix, int s, int e, int from, int to){
	propagation(ix, s, e);
	if (e < from || to < s) return mp(0, -1);
	if (from <= s&&e <= to){
		return mp(sum[ix], minima[ix] );
	}
	pair<ll, ll> l = query(ix + ix, s, (s + e) >> 1, from, to);
	pair<ll, ll> r = query(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to);
	return mp(l.first + r.first, min(l.second, r.second));

}
int main(){
	int i;
	int N, Q;
	int hay;
	int A, B, C;
	char inst;
	for (scanf("%d%d", &N, &Q), i = 0; i < N; i++){
		scanf("%d", &hay);
		update(1, 0, LEAF - 1, i, i, hay);
	}
	while (Q--){
		scanf(" %c%d%d", &inst, &A, &B);
		switch (inst){
		case 'M':case'S':{
			pair<ll, ll> p = query(1, 0, LEAF - 1, A - 1, B - 1);
			printf("%lld\n", inst == 'M' ? p.second : p.first);
			break;
		}
		case 'P':
			scanf("%d", &C);
			update(1, 0, LEAF - 1, A - 1, B - 1, C);
			break;
		}
	}
	return 0;
}