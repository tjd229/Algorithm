//math
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> seg[100001];//s,dist
int n, m;
int dist(int a, int b) {
	int dab = b - a;
	if (dab < 0) dab += n;
	int dba = n - dab;
	return dab < dba ? dab : dba;
}
int main() {
	for (scanf("%d%d", &n, &m); m--;) {
		int a, b; scanf("%d%d",&a,&b);
		int d = dist(a,b);
		seg[a].push_back(d);
		seg[b].push_back(d);
	}
	for (int i = 1; i <= n; ++i) sort(seg[i].begin(),seg[i].end());
	for (int i = 1; i < n; ++i) {
		if (n%i) continue;
		int l = 1, r = 1+i;
		bool flag = 1;
		for (; flag && l <= n; ++l,++r) {
			if (r > n) r -= n;
			if (seg[l].size() == seg[r].size()) {
				for (int j = 0; flag && j < seg[l].size(); ++j) {
					flag &= seg[l][j] == seg[r][j];
				}
			}
			else flag = 0;
		}
		if (flag) {
			printf("Yes");
			return 0;
		}
	}
	printf("No");
	return 0;
}