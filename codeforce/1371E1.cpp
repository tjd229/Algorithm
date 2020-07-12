//math, implementation
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int a[2000];
int n, p;
bool sim(int x) {
	int it = 0;	
	vector<int> d;
	for (int i = 0; i < n; ++i) {
		while (it < n && a[it] <= x) ++it;
		if (it <= i) return 0;
		d.push_back(it-i);
		++x;
	}
	//printf("%lld\n",cnt);
	for (auto x : d) if (x%p == 0) return 0;
	return 1;
}
int main() {
	int i;
	for (scanf("%d%d", &n, &p), i = 0; i < n; ++i) scanf("%d",a+i);
	sort(a , a + n);
	vector<int> ans;
	for (i = a[0]; i < a[n-1]; ++i) {
		if (sim(i)) ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for (auto x : ans) printf("%d ",x);
	return 0;
}
