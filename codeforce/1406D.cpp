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
ll d[100001];
ll b,c;
inline ll calc(ll d) {
	ll t1 = d >> 1;
	ll t2 = d - t1;
	return max(t1, t2);
	
}
void db(int n) {
	for (int i = 1; i <= n; ++i) printf("%lld,",d[i]);
	puts("");
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int i, n; cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	for (i = 1; i <= n; ++i) d[i] = a[i] - a[i - 1];
	for (i = 1; i <= n; ++i) {
		if (d[i] >= 0) b += d[i];
	}
	c = min(d[1], 0LL);
	ll diff = b - abs(c);
 
	//printf("%lld,%lld,%lld\n", diff, b, c);
	cout << calc(diff)<<"\n";
	int q; cin >> q;
	//db(n);
	while (q--) {
		int l, r, x; cin >> l >> r >> x;
		if (d[l] >= 0) 
			b -= d[l];
		d[l] += x;
		if (d[l] >= 0) b += d[l];
		
		if (r + 1 <= n) {
			if (d[r + 1] >= 0) {
				b -= d[r + 1];
			}
			d[r + 1] -= x;
			if (d[r + 1]  >= 0) b += d[r + 1] ;
			
		}
		c = min(d[1], 0LL);
		ll diff = b - abs(c);
		//printf("%lld,%lld,%lld\n",diff,b,c);
		cout << calc(diff) << "\n";
		//db(n);
	}
	return 0;
}
