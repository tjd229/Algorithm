//greedy

#include <stdio.h>
#include <set>
#define pii pair<int,int>
using namespace std;
int a[200000];
int ans[200000];
int main() {
	int n, m, d;
	int i;
	set<pii > st;
	for (scanf("%d%d%d", &n, &m, &d), i = 0; i < n; ++i) {
		scanf("%d",a+i);
		st.insert({a[i],i});
	}
	int day = 0;
	int last = 1e9+2;
	for (i = 0; i < n; ++i) {
		int bnd = last + 1 + d;
		auto it = st.lower_bound({ bnd,0 });
		if (it == st.end()) it = st.begin(), ++day;
		ans[it->second] = day;
		last = it->first;
		st.erase(it);
	}
	
	printf("%d\n",day);
	for (i = 0; i < n; ++i) printf("%d ",ans[i]);
	return 0;
}
