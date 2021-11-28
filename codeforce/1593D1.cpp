//math
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std; 
int gcd(int a, int b) {
	if (a > b) a ^= b ^= a ^= b;
	if (a == 0) return b;//a<b
	return gcd(b%a, a);
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i,n;
		vector<int> v,d;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			int a; scanf("%d",&a);
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
		if (v.size() == 1) printf("-1\n");
		else {
			for (i = 1; i < v.size(); ++i)
				d.push_back(v[i]-v[i-1]);
			int ans = d[0];
			for (i = 1; i < d.size(); ++i)
				ans = gcd(ans, d[i]);
			printf("%d\n",ans);
		}
	}
 
	return 0;
}