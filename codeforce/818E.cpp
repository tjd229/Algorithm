//category : ft, bs

#include <stdio.h>
#define ll long long
const int bnd = 1 << 17;
int n, k;
int a[100001];
ll ft[bnd + 1];
ll prod(int ix){
	ll res = 1;
	while (ix != 0){
		res = (res*ft[ix]) % k;
		ix -= (ix&-ix);
	}
	return res;
}
void update(int ix, int val){
	while (ix <= bnd){
		ft[ix] = (ft[ix] * val) % k;
		ix += (ix&-ix);
	}
}
int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main(){
	int i;
	ll ans = 0;
	for (scanf("%d%d", &n, &k), i = 1; i <= n; i++) scanf("%d",a+i),ft[i]=1;
	if (k == 1){
		printf("%I64d", ((ll)n*(n+1)) >> 1);
		return 0;
	}
	for (i = n; i > 0; i--){
		int d = k < a[i] ? gcd(a[i], k) : gcd(k, a[i]);
		update(i,d);
		int l = i;
		int r = n;
		while (l <= r){
			int m = (l + r) >> 1;
			d = prod(m);
			if (d) l=m+1; //d!=0
			else r = m - 1;
		}
		ans += n-r; //n-(r+1)+1
	}
	printf("%I64d",ans);
	return 0;
}
