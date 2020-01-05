//implementation
#include <stdio.h>
#include <set>
using namespace std;
int a[100001];
int b[100001];
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n, m;
		set<int> st;
		for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) scanf("%d",a+i);
		for (i = 1; i <= m; ++i) scanf("%d",b+i);
		int bag = 1;
		int done=0;
		long long ans = 0;
		for (i = 1; i <= m; ++i) {
			if (st.find(b[i]) != st.end()) {
				st.erase(b[i]);
				++ans;
			}
			else {
				while (a[bag] != b[i]) {
					st.insert(a[bag]);
					++bag;
				}
				int k = st.size();
				ans += k + k + 1;
				++bag;
			}
			++done;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}