//category : dp, st, lazy propagation

#include <stdio.h>
#include <memory.h>
#define ll long long
const int LEAF = 1 << 17;
ll st[LEAF + LEAF];
ll md[LEAF + LEAF];
int mh[LEAF + LEAF];
int lazy[LEAF + LEAF];
ll d[100001];
int t[100001];
int h[100001];
int jump[100001];
int l[100001];
int max(int a, int b){ return a > b ? a : b; }
ll min(ll a, ll b){ return a < b ? a : b; }
void propagate(int ix){
	if (lazy[ix] != 0){
		mh[ix] = lazy[ix];
		if (ix < LEAF){
			lazy[ix + ix] = lazy[ix + ix+1] = lazy[ix];
		}
		st[ix] = md[ix] + mh[ix];
		lazy[ix] = 0;
	}
}
void update(int ix,int s,int e,int from,int to,int h_val,ll d_val){
	propagate(ix);
	if (e < from || to < s) return;
	if (from <= s&&e <= to){
		if (d_val >= 0) md[ix] = d_val;
		lazy[ix] = h_val;
		propagate(ix);
	}
	else{
		update(ix + ix, s, (s + e) >> 1, from, to, h_val, d_val);
		update(1+ix + ix, 1+((s + e) >> 1),e, from, to, h_val, d_val);
		mh[ix] = max(mh[ix + ix], mh[ix + ix + 1]);
		md[ix] = min(md[ix + ix], md[ix + ix + 1]);
		st[ix] = min(st[ix + ix], st[ix + ix + 1]);
	}
}

int max_h(int ix, int s, int e, int from, int to){
	propagate(ix);
	if (e < from || to < s) return 0;
	if (from <= s&&e <= to) return mh[ix];
	return max(max_h(ix + ix, s, (s + e) >> 1, from, to), max_h(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to));
}
ll min_d(int ix, int s, int e, int from, int to){
	propagate(ix);
	if (e < from || to < s) return 40000LL*1e5;
	if (from <= s&&e <= to) return st[ix];
	return min(min_d(ix + ix, s, (s + e) >> 1, from, to), min_d(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to));
}
int main(){
	int i, j;
	int T;
	int N;
	int tc = 1;
	jump[0] = -1;
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	for (scanf("%d", &T); tc <= T; tc++){
		memset(st, 0, sizeof(st));
		memset(md, 0, sizeof(md));
		memset(mh, 0, sizeof(mh));
		memset(lazy, 0, sizeof(lazy));
		int last[100001] = { 0 };
		for (scanf("%d", &N), i = 1; i <= N; i++){
			scanf("%d%d",t+i,h+i);
			jump[i] = i - 1;
			l[i] = max(l[i - 1], last[t[i]]);
			last[t[i]] = i;
		}
		for (i = 1; i <= N; i++){
			//for (j = l[i - 1]; j < l[i]; j++)
				//update(1,0,LEAF-1,j,j,0,40000LL*1e5);
			j = jump[i];
			while (j >= l[i] && max_h(1, 0, LEAF - 1, jump[j] + 1, j) <= h[i]){
				update(1, 0, LEAF - 1, jump[j] + 1, j, h[i], -1);
				j = jump[j];
			}
			if (i - 1 != j) jump[i - 1] = j;
			d[i] = min_d(1, 0, LEAF - 1, l[i], i - 1);
			update(1,0,LEAF-1,i,i,0,d[i]);
			
		}
		printf("Case %d: %lld\n",tc,d[N]);
	}

	return 0;
}