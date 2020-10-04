//implementation
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> recon(int n,int x,int y,int diff) {
	if ((y - x) % diff) return { -1 };
	vector<int> v;
	int a = y;
	int vis = 0;
	while (n && a > 0) {
		if (a == x) vis = 1;
		v.push_back(a);
		--n; a -= diff;
	}
	if (vis == 0) return { -1 };
	a = y + diff;
	while (n) {
		v.push_back(a);
		a += diff;
		--n;
	}
	return v;
	
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n, x, y; scanf("%d%d%d",&n,&x,&y);
		vector<int> ans;
		for (i = 1; i < 50; ++i) {
			vector<int> v = recon(n, x, y, i);
			if (v[0] != -1) {
				ans = v;
				int mx = ans[0] < ans[1] ? ans[1] : ans[0];
				if (mx == y) break;
			}
		}
		for (auto x : ans)
			printf("%d ",x);
		printf("\n");
	}
 
	return 0;
}