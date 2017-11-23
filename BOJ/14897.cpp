//category : pst

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int LEAF = 1 << 20;
int st[21 * LEAF],l[21*LEAF],r[21*LEAF];
int a[1000001], tmp[1000001], nxt[1000001],root[1000001];
int cnt;
vector<int> comp;
int get_comp(int x){
	return lower_bound(comp.begin(), comp.end(), x) - comp.begin();
}
int make_tree(int pre,int s,int e,int pos,int val){
	if (e < pos || pos < s) return pre;
	int ix = ++cnt;
	if (e == pos&&s == pos) st[ix]+=val;
	else{
		l[ix] = make_tree(l[pre], s, (s + e) >> 1, pos,val);
		r[ix] = make_tree(r[pre], 1+((s + e) >> 1),e, pos,val);
		st[ix] = st[l[ix]] + st[r[ix]];
	}
	return ix;
}
int query(int ix,int s,int e,int low){
	if (e <= low) return 0;
	if (low < s) return st[ix];
	return query(l[ix], s, (s + e) >> 1, low) + query(r[ix], 1+( (s + e) >> 1),e, low);
}
int main(){
	int i;
	int N, Q;
	int ql, qr;
	for (scanf("%d",&N),i=1;i<=N;i++){
		scanf("%d",a+i);
		comp.push_back(a[i]);
	}
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(),comp.end())-comp.begin());
	for (i = 1; i <= N; i++) a[i] = get_comp(a[i]);
	for (i = N; i > 0; i--){
		nxt[i] = tmp[a[i]] == 0 ? N + 1 : tmp[a[i]];
		tmp[a[i]] = i;
	}
	ql = 0;
	for (i = 1; i <= N; i++){
		if (nxt[i] > N){
			ql++;
			root[i] = make_tree(root[i - 1], 0, LEAF - 1, nxt[i],ql);// , printf("%d ", nxt[i]);			
		}
		else
			root[i] = make_tree(root[i - 1], 0, LEAF - 1, nxt[i],1);// , printf("%d ", nxt[i]);
	}
	for (scanf("%d", &Q); Q--;){
		scanf("%d%d",&ql,&qr);
		printf("%d\n", query(root[qr], 0, LEAF - 1, qr) - query(root[ql-1], 0, LEAF - 1, qr));
	}

	return 0;
}
