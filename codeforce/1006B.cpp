//greedy
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define pii pair<int,int>
pii p[2001];
int main(){
	int i;
	int n, k;
	int a;
	int t = 0;
	vector<int> ans;
	for (scanf("%d%d", &n, &k), i = 1; i <= n; i++){
		scanf("%d",&a);
		p[i] = { a, i };
	}
	sort(p+1, p + 1+n);
	for (i = 0; i < k; i++){
		t += p[n - i].first;
		ans.push_back(p[n-i].second);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n",t);
	int last = 0;
	ans[k - 1] = n;
	for (i = 0; i < k; i++){
		printf("%d ", ans[i] - last);
		last = ans[i];
	}
	return 0;
}
