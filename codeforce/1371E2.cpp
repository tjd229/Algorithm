//math
#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int a[100000];
int cnt[100000];
int main() {
	int i, n, p;
	multiset<int> st;
	vector<int> ans;
	for (scanf("%d%d", &n, &p), i = 0; i < n; ++i) scanf("%d",a+i);
	sort(a, a + n);
	int x = a[n-1] - (n - 1);
	if (x < a[0]) x = a[0];
	int it = 0;
	for (i = 0; i < n && x <= a[n - 1]; ++i,++x) {
		while (it < n && a[it] <= x) ++it;
		cnt[i] = it;
		//if(i>0)
			st.insert((cnt[i] - cnt[0]) - i);
	}
	
	int pad = 0;
	x = a[n - 1] - (n - 1);
	if (x < a[0]) x = a[0];
	for (i = 0; i < n && x<a[n-1]; ++i,++x) {
		auto it = st.find((cnt[i] - cnt[0]) - i);
		st.erase(it);
		int init = cnt[i];
		int mx = init + *(--st.end()) + pad;
		int mn = init + *(st.begin()) + pad;
		//printf("%d,%d,%d\n",init,mn,mx);
		if (init > 0 && init < p && mn>0 && mx < p)
			ans.push_back(x);
		//++pad;
		pad += 1 -( cnt[i + 1] - cnt[i]);
	}
 
	printf("%d\n", ans.size());
	for (auto x : ans) printf("%d ", x);
	return 0;
}