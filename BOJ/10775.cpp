//implementation
#include <stdio.h>
#include <set>
using namespace std;
int g[100001];
int main() {
	int i, G, P;
	int ans = 0;
	set<int> gate;
	gate.insert(0);
	for (scanf("%d%d", &G, &P), i = 1; i <= G; ++i) gate.insert(i);
	gate.insert(i);
	for (i = 1; i <= P; ++i) scanf("%d",g+i);
	for (i = 1; i <= P; ++i, ++ans) {
		auto it = gate.lower_bound(g[i]);
		if (g[i] < *it) --it;
		if (*it == 0) break;
		gate.erase(it);
	}
	printf("%d",ans);
	return 0;
}