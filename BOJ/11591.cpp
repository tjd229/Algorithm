//category : ft

#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const int bnd = 1 << 20;
int ft[bnd + 1];
int a[1000001];
ll s[1000001];
void update(int ix, int d){
	while (ix <= bnd){
		ft[ix] += d;
		ix += (ix&-ix);
	}
}
int sum(int ix){
	int res = 0;
	while (ix){
		res += ft[ix];
		ix -= (ix&-ix);
	}
	return res;
}
int main(){
	int i;
	int N, P;
	ll ans = 0;
	vector<ll> v;
	for (scanf("%d", &N), i = 1; i <= N; i++) scanf("%d",a+i);
	for (scanf("%d", &P), i = 1; i <= N; i++){
		a[i] -= P;
		s[i] = s[i - 1] + a[i];
		v.push_back(s[i]);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (i = 1; i <= N; i++){
		ans += (s[i] >= 0);
		s[i] =1+lower_bound(v.begin(), v.end(), s[i]) - v.begin();	

		ans += sum(s[i]);
		update(s[i], 1);
	}
	printf("%lld",ans);
	return 0;
}
