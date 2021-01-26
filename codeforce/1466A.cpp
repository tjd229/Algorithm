//math, geometry
#include <stdio.h>
#include <set>
using namespace std; 
int x[101];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",x+i);
		set<int> st;
		for (int d = 1; d < 100; ++d) {
			for (i = 1; i + d <= n; ++i)
				st.insert(x[i+d]-x[i]);
		}
		printf("%d\n",st.size());
	}
	return 0;
}