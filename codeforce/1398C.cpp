//math
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
 
int a[100001];
 
int main() {
	
	int i, t; 
	for(scanf("%d",&t);t--;)
	{
		ll ac = 0;
		int n;
		map<ll, int> mp;
		mp[0] = 1;
		ll ans = 0;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%1d",a+i);
		for (i = 1; i <= n; ++i) {
			ac += a[i];
			ll x = ac - i;
			//printf("x:%lld\n",x);
			ans += mp[x];
			++mp[x];
		}
		printf("%I64d\n",ans);
	}
 
	return 0;
}