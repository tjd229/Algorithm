//line sweeping
#include <stdio.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int l[200001], r[200001];
int main() {
	int t; 
	for (scanf("%d", &t); t--;) {
		int i, n;
		vector<pii > evt;
		for (scanf("%d", &n), i = 1; i <= n;++i) {
			scanf("%d%d",l+i,r+i);
			evt.push_back({l[i],-i}); //op
			evt.push_back({r[i],i});//close
		}
		sort(evt.begin(), evt.end());
		vector<int> blk_list;
		int ans = n - 1; int stk = 0;
		for (auto p : evt) {
			if (p.second>0) {
				int ix = p.second;
				
				int d = stk +(blk_list.end()-lower_bound(blk_list.begin(), blk_list.end(), l[ix]));
				//printf("%d,%d,%d\n",ix,d,stk);
				if (ans > n - d) ans = n - d;
				--stk;
				blk_list.push_back(p.first);
			}
			else ++stk;
		}
		printf("%d\n",ans);
	}
	return 0;
}