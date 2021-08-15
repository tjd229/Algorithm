//greedy
#include <stdio.h>
#include <set>
using namespace std;
int a[100001];
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n, k;
		set<int> st;
		for (scanf("%d%d", &n,&k), i = 1; i <= n; ++i) {
			scanf("%d",a+i);
			st.insert(a[i]);
		}
		int cnt = 0;
		for (i = 1; i < n; ++i) {
			auto it = st.lower_bound(a[i]);
			if (++it != st.end()) {
				if (*it == a[1 + i]) ++cnt;
			}
		}
		if (n - cnt <= k) printf("Yes\n");
		else printf("No\n");
		
	}
 
	return 0;
}