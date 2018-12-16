//math

#include <stdio.h>
#define ll long long
ll gcd(ll a, ll b){
	if (a == 0) return b;
	return gcd(b%a, a);
}
ll min(ll a, ll b) { return a < b ? a : b; }
int main(){
	ll a, b, x, y;
	scanf("%I64d%I64d%I64d%I64d",&a,&b,&x,&y);
	ll c;
	if (x > y) c = gcd(y, x);
	else c = gcd(x, y);
	x /= c;
	y /= c;
	ll mxw = a / x;
	ll mxh= b / y;
	printf("%I64d",min(mxw,mxh));

	return 0;
}
