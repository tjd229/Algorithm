//greedy

#include <stdio.h>
#include <set>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;
int main() {
	int i;
	int N;
	int ans = 0;
	vector<pii > todo;
	set<int> table;
	for (scanf("%d", &N), i = 0; i < N; ++i) {
		int d, w;
		scanf("%d%d",&d,&w);
		todo.push_back({-w,d});
	}
	sort(todo.begin(), todo.end());
	for (i = 0; i <= 1000; ++i) table.insert(i);
	for (auto p : todo) {
		int w = -p.first;
		int d = p.second;
		auto it = table.upper_bound(d);
		if (*(--it)) {
			ans += w;
			table.erase(it);
		}
	}
	printf("%d",ans);
	return 0;
}
