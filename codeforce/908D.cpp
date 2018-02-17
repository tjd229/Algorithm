//category : math, dp
//idea ref : http://drugstoreoftamref.tistory.com/44
//idea ref : https://kimiyuki.net/blog/2017/12/30/cf-908-d/
#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;
ll e[1001][1001];
bool visit[1001][1001];
int k, pa, pb;
int A, B,invB;
ll pow(ll x, int n){
	ll res = 1;
	while (n != 0){
		if (n & 1){
			res = res*x%mod;
		}
		x = x*x%mod;
		n >>= 1;
	}
	return res;
}
ll expected(int na,int nab){
	if (nab >= k) return 0;
	if (na >= k) return (k-1+invB)%mod;
	if (visit[na][nab]) return e[na][nab];
	visit[na][nab] = true;
	e[na][nab] = A*expected(na + 1, nab)%mod + B*(expected(na, na + nab)+na)%mod;
	e[na][nab] %= mod;
	return e[na][nab];
}
int main(){
	scanf("%d%d%d",&k,&pa,&pb);
	A = pa*pow(pa + pb, mod - 2) % mod;
	B = pb*pow(pa + pb, mod - 2) % mod;
	invB = pa + pb;
	invB = invB%pb ? invB*pow(pb, mod - 2) % mod : invB / pb;
	
	printf("%I64d",expected(1,0));

	return 0;
}
