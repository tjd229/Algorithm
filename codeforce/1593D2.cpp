//math
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std; 
const int inf = 1e9;
 
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
		int ans = 1;
		for (int i = 0; i < v.size() && ans<inf; ++i) {
			for (int j = i + 1; j < v.size() && ans<inf; ++j) {
				int d = v[j] - v[i];
				int cnt = 0;
				if (d == 0) {
					for (int k = i; k < v.size(); ++k)
						cnt += v[k] == v[i];
					if (cnt + cnt >= n) ans = inf;
				}
				else {
					vector<int> divs = {d};
					for (int k = 2; k*k <= d; ++k) {
						if (d%k == 0) {
							divs.push_back(k);
							divs.push_back(d / k);
						}
					}
					
					
					for (auto d : divs) {
						cnt = 0;
						for (int k = 0; k < v.size(); ++k) {
							int dist = k > i ? v[k] - v[i] : v[i] - v[k];
							cnt += (dist % d) == 0;
						}
						//printf("(%d,%d)|divs:%d,%d\n", i,j,d,cnt);
						if (cnt + cnt >= n && d > ans) ans = d;
					}
				}
 
				
			}
		}
		if (ans == inf) ans = -1;
		printf("%d\n",ans);
 
 
	}
 
	return 0;
}