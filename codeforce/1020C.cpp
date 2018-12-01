//greedy
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> fan[3001];
int main() {
	int i;
	int n, m;
	long long ans = 3e12;
	for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) {
		int p, c;
		scanf("%d%d",&p,&c);
		fan[p].push_back(c);
	}
	for (int i = 2; i <= m; ++i) sort(fan[i].begin(), fan[i].end());
	for (int v = 1; v <= n; ++v) {
		priority_queue<int> remain;
		int Berland = fan[1].size();
		long long cost = 0;
		for (int j = 2; j <= m; ++j) {
			for (int k = 0; k < fan[j].size(); ++k) {
				if (fan[j].size() - k < v) remain.push(-fan[j][k]);
				else {
					cost += fan[j][k];
					++Berland;
				}
			}	
		}
		while (Berland < v) {
			cost -= remain.top();
			remain.pop();
			++Berland;
		}
		if (ans > cost) ans = cost;
	}
	printf("%I64d",ans);
	return 0;
}
