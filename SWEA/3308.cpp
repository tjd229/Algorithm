//category : st

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
const int LEAF = 1 << 18;
int A[100001];
int st[LEAF + LEAF];
int max(int a, int b){ return a < b ? b : a; }
void update(int ix,int val){
	st[ix] = val;
	ix >>= 1;
	while (ix != 0){
		st[ix] = max(st[ix + ix], st[ix + ix + 1]);
		ix >>= 1;
	}
}
int query(int ix,int s,int e,int from,int to){
	if (e < from || to < s) return 0;
	if (from <= s&&e <= to) return st[ix];
	return max(query(ix + ix, s, (s + e) >> 1, from, to), query(ix + ix+1, 1+( (s + e) >> 1),e, from, to) );
}
int compress(int x,const vector<int> &v){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int main(){
	int T;
	int tc = 1;
	int i;
	int N;
	int ans;
	int x,c;
	for (scanf("%d", &T); tc <= T; tc++){
		ans = 0;
		vector<int> v;
		memset(st, 0, sizeof(st));
		for (scanf("%d", &N), i = 1; i <= N; i++){
			scanf("%d", A + i);
			if (A[i] > N) v.push_back(A[i]);
		}
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(),v.end())-v.begin());
		
		for (i = 1; i <= N; i++){
			if (A[i] > N){
				A[i] = N + compress(A[i],v);
			}
			x = query(1,0,LEAF-1,0,A[i]);
			update(LEAF+A[i],x+1);
			ans = max(ans, x + 1);
			
		}
		printf("#%d %d\n",tc,ans);

	}

	return 0;
}
