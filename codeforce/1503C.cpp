//graph, greedy
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define ll long long
using namespace std;
int a[100000], c[100000];
int main() {
	int i,n;
	vector<pii > v;
	for (scanf("%d", &n), i = 0; i < n; ++i) {
		scanf("%d%d", a + i, c + i);
		v.push_back({a[i],c[i]});
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	for (i = 0; i < n; ++i) {
		a[i] = v[i].first, c[i] = v[i].second;
		ans += c[i];
	}
	int mx = a[0] + c[0];
	for (i = 1; i < n; ++i) {
		ans += max(0, a[i] - mx);
		if (mx < a[i] + c[i]) mx = a[i] + c[i];
	}
	printf("%I64d",ans);
 
	return 0;
}