//greedy
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
int a1[300001];
int a2[300001];
int a3[300001];
int main() {
	int i, n1, n2, n3;
 
	ll s1 = 0, s2 = 0, s3 = 0;
	for (scanf("%d%d%d", &n1, &n2, &n3), i = 1; i <= n1; ++i) scanf("%d",a1+i),s1+=a1[i];
	for (i = 1; i <= n2; ++i) scanf("%d", a2 + i), s2 +=a2[i];
	for (i = 1; i <= n3; ++i) scanf("%d", a3 + i), s3 += a3[i];
	sort(a1 + 1, a1 + 1 + n1); sort(a2 + 1, a2 + 1 + n2); sort(a3 + 1, a3 + 1 + n3);
	
	ll S = s1 + s2 + s3;
	ll ans = 0;
	if (n1 > 1 && n2 > 1) {
		ll num = S - a1[1] - a2[1]-a1[1]-a2[1];
		if (ans < num) ans = num;
	}
	if (n3 > 1 && n2 > 1) {
		ll num = S - a3[1] - a2[1] - a3[1] - a2[1];
		if (ans < num) ans = num;
	}
	if (n1 > 1 && n3 > 1) {
		ll num = S - a1[1] - a3[1] - a1[1] - a3[1];
		if (ans < num) ans = num;
	}
	ll num = S - s1 - s1;
	if (ans < num) ans = num;
	num = S - s2 - s2;
	if (ans < num) ans = num;
	num = S - s3 - s3;
	if (ans < num) ans = num;
 
	printf("%I64d\n",ans);
 
 
	return 0;
}