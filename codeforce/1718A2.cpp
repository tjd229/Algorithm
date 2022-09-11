//dp
#include <stdio.h>
#include <set>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int a[100001];
int d[100001];
int k[100002];
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n; int j;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			scanf("%d", a + i);
		}
		if (n == 1) {
			printf("%d\n", a[1] > 0);
			continue;
		}
		set<pii > st;
		int cumxor = 0;
		for (i = 1; i <= n; ++i) a[i] ^= a[i - 1];
		st.insert({0,0});
		
		for (i = 1; i <= n; ++i) {
			
			d[i] = d[i - 1] + 1;
			pii key = { a[i],i };
			//printf("%d\n",postcum);
			auto it = st.lower_bound(key);
			if (it != st.begin()) {
				it = prev(it);
				if (it->first == a[i] ) {
					int len = i - it->second ;
					d[i] = min(d[i], d[it->second ] + len - 1);
				}
			}
			st.insert(key);
		}
		printf("%d\n", d[n]);
 
 
 
	}
 
	return 0;
}