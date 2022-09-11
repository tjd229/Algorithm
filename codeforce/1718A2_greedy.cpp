//greedy
#include <stdio.h>
#include <set>
using namespace std;
int a[100001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i),a[i]^=a[i-1];
		set<int> st; st.insert(0);
		int ans = n;
		for (i = 1; i <= n; ++i) {
			if (st.find(a[i]) != st.end()) {
				--ans; st.clear();
			}
			st.insert(a[i]);
		}
		printf("%d\n",ans);
	}
 
	return 0;
}