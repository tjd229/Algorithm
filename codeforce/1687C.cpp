//implementation, bs
#include <stdio.h>
#include <set>
#include <queue>
#define ll long long
using namespace std;
vector<int> L[200001], R[200001];
ll s[200001];
int l[200000], r[200000];
int op[200000];
void rm(vector<int> &v, int x) {
	v[x] = v.back();
	v.pop_back();
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n,m;
		set<int> pos;
		
		queue<int> q;
		for (scanf("%d%d", &n,&m), i = 1; i <= n; ++i) {
			int a; scanf("%d",&a);
			s[i] =  a;
			L[i].clear(); R[i].clear();
		}
		for (i = 1; i <= n; ++i) {
			int b; scanf("%d",&b);
			s[i] += s[i-1]-b;
			if (s[i]) pos.insert(i);
		}
		for (i = 0; i < m; ++i) {
			scanf("%d%d", l + i, r + i);
			op[i] = 0;
			if (s[l[i] - 1] == 0 && s[r[i]] == 0) {
				auto it = pos.lower_bound(l[i]);
				while (it != pos.end() && *it <= r[i]) {
					auto nxt = next(it);
					q.push(*it); s[*it] = 0;
					pos.erase(it);
					it = nxt;
				}
				op[i] = 1;
			}
			else {
				L[l[i]].push_back(i);
				R[r[i]].push_back(i);
			}
		}
		if (s[n]) {
			printf("NO\n");
			continue;
		}
 
		while (q.size() && pos.size() ) {
			int x = q.front(); q.pop();
			vector<int> &right_base = R[x];
			for (i = 0; i < right_base.size();) {
				int ix = right_base[i];
				if (op[ix] || (s[l[ix] - 1] == 0 && s[r[ix]] == 0)) {
					auto it = pos.lower_bound(l[ix]);
					while (it != pos.end() && *it <= r[ix]) {
						auto nxt = next(it);
						q.push(*it); s[*it] = 0;
						pos.erase(it);
						it = nxt;
					}
					op[ix] = 1;
					rm(right_base, i);
				}
				else ++i;
			}
 
			vector<int> &left_base = L[x+1];
			for (i = 0; i < left_base.size();) {
				int ix = left_base[i];
				if (op[ix] || (s[l[ix] - 1] == 0 && s[r[ix]] == 0)) {
					auto it = pos.lower_bound(l[ix]);
					while (it != pos.end() && *it <= r[ix]) {
						auto nxt = next(it);
						q.push(*it); s[*it] = 0;
						pos.erase(it);
						it = nxt;
					}
					op[ix] = 1;
					rm(left_base, i);
				}
				else ++i;
			}
			
		}
		//for (i = 1; i <= n; ++i) printf("%lld ",s[i]);
		if (pos.size()) printf("NO\n");
		else printf("YES\n");
 
	}
 
	return 0;
}