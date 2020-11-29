//dp
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
int d[100001],a[100001];
int vis[100001];
int n, p, k;
int sim(int x,int stamp) {	
	if (x > n) return 0;
	if (vis[x] == stamp) return d[x];
	vis[x] = stamp;
	d[x] = sim(x + k,stamp);
	if (a[x] == 0) ++d[x];
	return d[x];
}
int main() {
	int t; scanf("%d",&t);
	while (t--) {
		int i; scanf("%d%d%d",&n,&p,&k);
		int x, y;
		for (i = 1; i <= n; ++i)scanf("%1d",a+i);
		scanf("%d%d",&x,&y);
		for (i = 1; i <= n; ++i) sim(i, t + 1);
		ll ans = -1;
		int rm = 0;
		for (i = p; i <= n; ++i,++rm) {
			if (n - rm < p) break;
			ll cost = d[i] * (ll)x;
			cost += rm * (ll)y;
			if (ans<0 || ans > cost) ans = cost;
		}
		printf("%I64d\n",ans);
	}
 
 
	return 0;
}