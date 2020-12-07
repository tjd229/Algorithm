//math
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int i, t;
	long long mx = 1e18;
	//printf("%d",mx<(1LL<<59));->0
	for (scanf("%d", &t); t--;) {
		long long k; scanf("%I64d",&k);
		if (k & 1) {
			printf("-1\n");
			continue;
		}
		else if (k == 2) {
			printf("1\n1\n");
			continue;
		}
		vector<int> v;
		int stage = 0;
		while (k) {
			v.push_back(1);
			long long stk = 2;
			long long delta = 4;
			while (k >= stk + delta) {
				stk += delta;
				delta += delta;
				v.push_back(0);
			}
			k -= stk;
		}
 
		printf("%d\n",v.size());
		for (auto x : v) printf("%d ",x);
		printf("\n");
	}
 
	return 0;
}