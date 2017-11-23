//category : dp, st, lazy propagation, djs

#include <stdio.h>
#include <memory.h>
#define ll long long
const int LEAF = 1 << 17;
int mh[LEAF + LEAF];
int lazy[LEAF + LEAF];
ll md[LEAF + LEAF];
ll st[LEAF + LEAF];
ll d[100001];
int h[100001];
int t[100001];
int l[100001];
int last[20001];
int p[100001];
int maxima[100001];
int max(int a, int b){ return a < b ? b : a; }
ll min(ll a, ll b){ return a < b ? a : b; }
void propagate(int ix){
	if (lazy[ix] != 0){
		mh[ix] = lazy[ix];
		if (ix < LEAF){
			lazy[ix + ix] = lazy[ix + ix+1] = lazy[ix ];
		}
		st[ix] = md[ix] + mh[ix];
		lazy[ix] = 0;
	}
}
void update(int ix,int s,int e,int from,int to,int h_val,ll d_val){
	//propagate(ix);
	if (e < from || to < s) return;
	propagate(ix);
	if (from <= s&&e <= to){
		if (d_val>=0) md[ix] = d_val;
		lazy[ix] = h_val;
		propagate(ix);		
	}
	else{
		update(ix + ix, s, (s + e) >> 1, from, to, h_val, d_val);
		update(ix + ix+1, 1+( (s + e) >> 1), e,from, to, h_val, d_val);
		mh[ix] = max(mh[ix + ix], mh[ix + ix + 1]);
		md[ix] = min(md[ix + ix], md[ix + ix + 1]);
		st[ix] = min(st[ix + ix], st[ix + ix + 1]);
	}
}
int query2(int ix, int s, int e, int from, int to){
	propagate(ix);
	if (e < from || to < s) return 0;
	if (from <= s&&e <= to) return mh[ix];
	return max(query2(ix + ix, s, (s + e) >> 1, from, to), query2(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to));
}
ll query3(int ix,int s,int e,int from,int to){
	//propagate(ix);
	if (e < from || to < s) return (ll)40000 * 1e5;
	propagate(ix);
	if (from <= s&&e <= to) return st[ix];
	return min(query3(ix + ix, s, (s + e) >> 1, from, to), query3(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to));
}
int find(int a){
	if (a != p[a]) p[a] = find(p[a]);
	return p[a];
}
void join(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (maxima[a] < maxima[b]) maxima[a] = maxima[b];
	p[b] = a;
}
int main(){
	int i,j;
	int T;
	int tc = 1;
	int N;
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	for (scanf("%d", &T); tc <= T; tc++){
		memset(mh, 0, sizeof(mh));
		memset(md, 0, sizeof(md));
		memset(lazy, 0, sizeof(lazy));
		memset(last, 0, sizeof(last));
		memset(st, 0, sizeof(st));
		
		for (scanf("%d", &N), i = 1; i <= N; i++){
			scanf("%d%d",t+i,h+i);
			l[i] = max(l[i - 1], last[t[i]]);
			last[t[i]] = i;
			p[i] = i;
			maxima[i] = 0;
		}
		for (i = 1; i <= N; i++){
			//for (j = l[i - 1]; j < l[i]; j++)
				//update(1,0,LEAF-1,j,j,0,(ll)40000*1e5);
			j = i - 1;
			maxima[j] = h[i];
			while (j >= l[i] && maxima[find(j)] <= h[i]){
				//printf("%d~%d:%d\n",find(j),j,maxima[find(j)]);
				join(find(j),i-1);
				//update(1,0,LEAF-1,jump[j]+1,j,h[i],-1);
				j = find(j)-1;
			}
			update(1, 0, LEAF - 1, max(l[i],find(i-1)), i - 1, h[i], -1);
			d[i] = query3(1,0,LEAF-1,l[i],i-1);
			update(1, 0, LEAF - 1, i, i, 0, d[i]);
			//printf("%d,%d),%lld\n",find(i-1),maxima[find(i-1)],d[i]);
		}
		printf("Case %d: %lld\n",tc,d[N]);
	}
}

