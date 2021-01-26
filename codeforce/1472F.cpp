//greedy
#include <stdio.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int wall[200002];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n,m;
		vector<pii > v;
		for (scanf("%d%d", &n,&m), i = 0; i < m; ++i) {
			int r, c; scanf("%d%d",&r,&c);
			v.push_back({c,r});
			wall[i] = 0;
		}
		v.push_back({ n + 1,1 }); v.push_back({ n + 1,2 });
		wall[m + 1] = wall[m ] = 1; m += 2;
 
		sort(v.begin(), v.end());
		int stk = -1;
		bool flag = 1;
		for (i = 1; i < m; ++i) {
			if (v[i].first == v[i - 1].first) wall[i] = wall[i - 1] = 1;
		}
		for (i = 0; flag && i < m; ++i) {
			
			if (stk < 0) stk = i;
			else {
				int prer = v[stk].second, prec = v[stk].first;
				int r = v[i].second, c = v[i].first;
				if (wall[i] != wall[stk]) flag = 0;
				if (r == prer) {
					int d = c - prec;
					if ((d & 1)==0) flag = 0;
				}
				else {
					int d = c - prec;
					if (d&1) flag = 0;
				}
				stk = -1;
			}
		}
		printf("%s\n",stk<0 && flag? "YES":"NO");
		
	}
 
	return 0;
}