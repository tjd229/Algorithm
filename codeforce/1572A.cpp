//graph, tp sort
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> edge[200001];
int k[200001];
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n; 
		priority_queue<int> q;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			k[i] = 0;
			edge[i].clear();
		}
		for (i = 1; i <= n; ++i) {
			scanf("%d",k+i);
			for (int j = 0; j < k[i]; ++j) {
				int a; scanf("%d",&a);
				edge[a].push_back(i);
			}
			if (k[i] == 0) q.push(-i);
		}
		int done = 0;
		int ans = 0;
		while (done < n) {
			vector<int> src; ++ans;
			while (q.size()) {
				int x = -q.top(); q.pop();
				++done;
				for (auto nxt : edge[x]) {
					--k[nxt];
					if (k[nxt] == 0) {
						if (nxt > x) q.push(-nxt);
						else src.push_back(nxt);
					}
				}
			}
			if (src.empty()) break;
			for (auto x : src) q.push(-x);
		}
		if (done < n) ans = -1;
		printf("%d\n",ans);
	}
 
	return 0;
}