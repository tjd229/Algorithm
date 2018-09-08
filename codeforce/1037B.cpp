//greedy

#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
int a[(int)2e5];
int main(){
	int i;
	int n, s;
	ll ans = 0;
	for (scanf("%d%d", &n,&s), i = 0; i < n; i++) scanf("%d",a+i);
	int m = n >> 1;
	sort(a, a + n);
	int d = 1;
	if (a[m] < s){
		i = m;
		while (a[i]<s && i<n){
			ans += s - a[i];
			i++;
		}
	}
	else if(a[m]>s){
		i = m;
		while (a[i] > s && i >= 0){
			ans += a[i]-s;
			--i;
		}
	}
	printf("%I64d",ans);
	return 0;
}
