//category : pst

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int LEAF = 1 << 18;
struct Query{
	int L, R, K;
}q[100000];
int A[100001];
int root[100001];
int st[19*LEAF], l[LEAF*19], r[LEAF*19];
int cnt;
int compress(int x,vector<int> &v){
	return lower_bound(v.begin(), v.end(), x) - v.begin()+1;
}
int make_tree(int pre,int s,int e,int pos){
	if (e < pos || pos < s) return pre;
	int ix = ++cnt;
	if (s == e){
		st[ix]=st[pre]+1;
	}
	else{
		l[ix] = make_tree(l[pre], s, (s + e) >> 1, pos);
		r[ix] = make_tree(r[pre], 1+((s + e) >> 1),e, pos);
		st[ix] = st[l[ix]] + st[r[ix]];
	}
	return ix;
}
int query(int ix,int s,int e,int bnd){
	if (s > bnd) return 0;
	if (e <= bnd){
		return st[ix];
	}
	else
		return query(l[ix], s, (s + e) >> 1, bnd) + query(r[ix], 1+((s + e) >> 1),e, bnd);
}
int main(){
	int i,k;
	int T;
	int tc=1;
	int N,M;
	int ans;
	for (scanf("%d", &T); tc <= T; tc++){
		scanf("%d", &N);		
		vector<int> v;
		cnt = 0;
		printf("#%d ",tc);
		for (i = 1; i <= N; i++){
			scanf("%d",A+i);
			v.push_back(A[i]);
		}
		for (scanf("%d", &M), i = 0; i < M; i++){
			scanf("%d%d%d", &q[i].L, &q[i].R, &q[i].K);
			v.push_back(q[i].K);
		}
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(),v.end())-v.begin());
		for (i = 1; i <= N; i++){
			root[i] = make_tree(root[i - 1], 0, LEAF - 1, compress(A[i],v));
		}
		for (i = 0; i < M; i++){
			k = compress(q[i].K,v);
			ans = st[root[q[i].R]] -query(root[q[i].R], 0, LEAF - 1, k);
			ans -= st[root[q[i].L-1]] - query(root[q[i].L-1], 0, LEAF - 1, k);
			printf("%d ",ans);
		}
		printf("\n");
	}

	return 0;
}
