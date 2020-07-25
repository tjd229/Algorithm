//game, math
#include <stdio.h>
#define ll long long
int main() {
	ll a, b, c; scanf("%I64d%I64d%I64d",&a,&b,&c);
	printf("First\n"); fflush(stdout);
	bool flag = 1;
	ll mx = a; int l = 1;
	if (mx < b) mx = b, l = 2;
	if (mx < c) mx = c, l = 3;
	while (flag) {		
		ll y = mx + mx;
		if (mx != a) y -= a;
		if(mx!=b) y-=b;
		if (mx != c) y -= c;
		printf("%I64d\n", y); fflush(stdout);
		int place; scanf("%d",&place);
		if (place == 1) a += y,mx=a;
		else if (place == 2) b += y,mx=b;
		else c += y,mx=c;
		flag = place == l;
		l = place;
	}
	ll y = 0;
	if (mx == a) y = b - c;
	else if (mx == b) y = c - a;
	else y = a - b;
	if (y < 0) y = -y;
	printf("%I64d\n", y); fflush(stdout);
	scanf("%I64d",&y);
	return 0;
}