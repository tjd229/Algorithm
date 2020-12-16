//math
#include <stdio.h>
#include <deque>
#include <algorithm>
#define ll long long
using namespace std;
int a[200001];
 
ll nck(int n, int k) {
	if (n < k) return 0;
	if (k == 0) return 1;
	ll res = 1; 	
	for (int i = 0; i < k; ++i) res *= n - i;
	if (k == 2) res >>= 1;
	else if (k == 3) res /= 6;
	return res;
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		ll ans = 0;
		int i, n, m=3, k=2;
		deque<int> dq;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i);
		sort(a + 1, a + 1 + n); i = 1;
		
		while (i <= n) {
			int piv = a[i]; int j = i;
			while (j <= n && piv == a[j])
				++j;
			while (dq.size() && piv- dq.front() > k) dq.pop_front();
			for (int l = 1; l <= m; ++l) {
				ll t1 = nck(dq.size(),m-l);
				ll t2 = nck(j - i, l);
				ans = (ans + t1 * t2);
			}
			while (i < j) dq.push_back(a[i++]);
			//printf("piv:%d,dq.size():%d\n",piv,dq.size());
			//printf("%lld\n", nck(dq.size(), m));
			//ans = (ans + nck(dq.size(), m))%mod;
		}
		printf("%I64d\n",ans);
	}
	
}