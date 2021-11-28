//greedy
#include <stdio.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int a[200001];
int x[200001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		x[0] = 0;
		int i, n;
		vector<pii > v;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			scanf("%d",a+i);
			v.push_back({a[i],i});
		}
		sort(v.begin(), v.end());
		long long l = -1, r = 1;
		long long T = 0;
		while (v.size()) {
			int b = v.back().second; v.pop_back();
			x[b] = l; T -= l * a[b]; --l;
			if (v.size()) {
				b = v.back().second; v.pop_back();
				x[b] = r; T += r * a[b]; ++r;
			}
			
		}
		for (printf("%I64d\n", T+T), i = 0; i <= n; ++i) printf("%d ",x[i]);
		puts("");
	}
 
	return 0;
}