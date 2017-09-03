//category : pst

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int st[2000000], left[2000000], right[2000000];
int a[100000],root[100000];
int decomp[100001];
vector<int> comp;
int ix;
int compress(int x){
	return lower_bound(comp.begin(), comp.end(), x)-comp.begin() + 1;
}
int make_tree(int pre,int s,int e,int pos){
	if (s > pos || e < pos) return pre;
	int cur = ++ix;
	if (s == e){
		st[cur] = st[pre] + 1;
		return cur;
	}
	left[cur] = make_tree(left[pre], s, (s + e) >> 1, pos);
	right[cur] = make_tree(right[pre], 1 + ((s + e) >> 1), e, pos);
	st[cur] = st[left[cur]] + st[right[cur]];
	return cur;
}
int query(int i,int j,int s,int e,int k){
	if (s == e) return s;
	int l = st[left[j]] - st[left[i]];
	if (l >= k) return query(left[i],left[j],s,(s+e)>>1,k);
	return query(right[i], right[j], 1+((s + e) >> 1),e, k-l);
}
int main(){
	int i,j,k;
	int n, m;
	scanf("%d%d",&n,&m);
	for (i = 0; i < n; i++) scanf("%d",a+i),comp.push_back(a[i]);
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(),comp.end()),comp.end());
	for (i = 1; i <= comp.size(); i++) decomp[i] = comp[i-1];

	for (i = 0; i < n; i++){
		root[i + 1] = make_tree(root[i], 1, comp.size(), compress(a[i]));
	}

	while (m--){
		scanf("%d%d%d",&i,&j,&k);
		printf("%d\n", decomp[query(root[i - 1], root[j], 1, comp.size(), k)]);
		
	}
	

	return 0;
}