//line sweeping
#include <stdio.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int a[6];
int b[100001];
int in[100001];
int main() {
	int i, n;
	vector<pii > v;
	for (i = 0; i < 6; ++i) scanf("%d",a+i);
	for (scanf("%d", &n), i = 1; i <= n; ++i) 
		scanf("%d", b + i);
	sort(b + 1, b + 1 + n);
	for (i = 1; i <= n; ++i) for (int j = 0; j < 6; ++j) v.push_back({b[i]-a[j],i});	
	sort(v.begin(), v.end());
	int l = 0, r = 0;
	int ans = -1;
	int s = 0;
	for (; l < v.size(); ++l) {
		while (r < v.size() && s < n) {
			if (++in[v[r].second] == 1) ++s;
			++r;
		}
		if (s == n) {
			if(ans<0 || ans>v[r - 1].first - v[l].first)
				ans=v[r - 1].first - v[l].first;
		}
		if (--in[v[l].second]==0) --s;
	}
	printf("%d",ans);
	return 0;
}