//graph
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
int cell[300001];
int a[300001], t[300001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q; cin >> q;
	while (q--) {
		int i, n,k; cin >> n>>k;
		for (i = 1; i <= n; ++i) cell[i] = 2e9;
		priority_queue<pii > pq;
		for (i = 0; i < k; ++i) cin >> a[i];
		for (i = 0; i < k; ++i) {
			cin >> t[i];
			pq.push({-t[i],a[i]});//min heap
			cell[a[i]] = t[i];
		}
		while (pq.size()) {
			int a, t; tie(t, a) = pq.top();
			pq.pop();
			t = -t;
			if (t != cell[a]) continue;
			if (a > 1) {
				if (cell[a - 1] > t + 1) {
					cell[a - 1] = t + 1;
					pq.push({ -cell[a - 1],a - 1 });
				}
			}
			if (a < n) {
				if (cell[a + 1] > t + 1) {
					cell[a + 1] = t + 1;
					pq.push({ -cell[a + 1],a + 1 });
				}
			}
		}
		for (i = 1; i <= n; ++i) cout << cell[i] << " ";
		cout << "\n";
		
	}
 
	return 0;
}