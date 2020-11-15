//math
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[100001]; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> ans;
	int i, n; cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	bool same = 1;
	for (i = 2; i <= n && same; ++i) same &= a[i] == a[i - 1];
	if (same) {
		cout << "YES\n0";
		return 0;
	}
	if ((n & 1)==0) {
		int tot = 0;
		for (i = 1; i <= n; ++i) tot ^= a[i];
		if (tot) {
			printf("NO\n");
			return 0;
		}
		--n;
	}
	
	for (i = 1; i < n; i += 2) {
		ans.push_back(i);
		ans.push_back(i + 1);
		ans.push_back(i + 2);
	}
	for (i = 1; i < n; i += 2) {
		ans.push_back(i);
		ans.push_back(i + 1);
		ans.push_back(n);
	}
	printf("YES\n%d\n",ans.size()/3);
	for (i = 0; i < ans.size();) {
		printf("%d ", ans[i++]);
		printf("%d ", ans[i++]);
		printf("%d\n", ans[i++]);
	}
	
	return 0;
}