//greedy
#include <stdio.h>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;
int pick[2001];
int p[2001];
int ab[2001];
int main() {
	int i;
	int n, m,t,r;
	vector<pii > order, pairs;
	for (scanf("%d%d", &n, &m), i = 1, r = n + n; i <= r; ++i) {
		scanf("%d",p+i);
		order.push_back({-p[i],i});
	}
	for (sort(order.begin(), order.end()), i = 0; i < m; ++i) {
		int a, b; scanf("%d%d",&a,&b);
		pairs.push_back({a,b});
		ab[a] = b; ab[b] = a;
	}
	scanf("%d",&t);
	int force = 0; i = 0;
	while (r--) {
		if (t == 1) {
			if (force && !pick[force]) {
				printf("%d\n", force); fflush(stdout);
				pick[force] = 1;
			}
			else {
				while (pairs.size() 
					&&(pick[pairs.back().first]|| pick[pairs.back().second])) {
					pairs.pop_back();
				}
				if (pairs.size()) {//stk
					int a = pairs.back().first;
					int b = pairs.back().second;
					if (p[a] < p[b]) a ^= b ^= a ^= b;
					printf("%d\n", a); fflush(stdout);
					pick[a]=1;
				}
				else {
					while (pick[order[i].second]) ++i;
					int x = order[i++].second;
					printf("%d\n", x); fflush(stdout);
					pick[x] = 1;
				}
			}
		}
		else {
			int x; scanf("%d",&x);
			pick[x] = 1;
			force = ab[x];
		}
		t = 3 - t;
	}
	return 0;
}