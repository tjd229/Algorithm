//category : bs, MITM
//reference : http://codeforces.com/contest/912/submission/33937258
#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const ll bnd = 1e18;

vector<int> pa, pb;
vector<ll> A, B;
void make_set(int ix,ll val,vector<ll> &S, const vector<int> &p_list){
	if (ix == p_list.size()) return;
	make_set(ix + 1, val, S,p_list);
	
	while (p_list[ix] <= bnd/val){
		val *= p_list[ix];
		S.push_back(val);
		make_set(ix+1,val,S,p_list);
	}


}
ll kth(ll val){
	ll k = 0;
	int i, j;
	for (i = 0, j = B.size() - 1; i < A.size()&&j>=0; i++){
		while (j>=0&& B[j] > val/A[i]) j--;
		k += j+1;
	}
	return k;
}
int main(){
	int i,j;
	int n;
	int p;
	ll l, r, m;
	ll k;
	
	for (i = 0, scanf("%d", &n); i < n; i++){
		scanf("%d",&p);
		if (i & 1) pb.push_back(p);
		else pa.push_back(p);
	}
	scanf("%I64d",&k);
	A.push_back(1);
	B.push_back(1);
	make_set(0,1, A, pa);
	make_set(0,1, B, pb);
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	l = 1;
	r = bnd;
	while (l <= r){
		m = (l + r) >> 1;
		if (k <= kth(m)){
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
	printf("%I64d", r + 1);
	
	
	
	return 0;
}
