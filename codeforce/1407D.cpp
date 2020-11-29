//dp
#include <stdio.h>
#include <vector>
using namespace std;
int h[300001], d[300001];
vector<int> to[300001];
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%d",h+i);
		to[i].push_back(i + 1);
		d[i] = -1;
	}
	to[n].clear(); d[1] = 0;
	vector<int> stk;
	for (i = 1; i <= n; ++i) {
		while (stk.size() && h[stk.back()] < h[i])
			stk.pop_back();
		if (stk.size())
			to[stk.back()].push_back(i);
		stk.push_back(i);
	}
	for (stk.clear(), i = 1; i <= n; ++i) {
		while (stk.size() && h[stk.back()] > h[i])
			stk.pop_back();
		if (stk.size())
			to[stk.back()].push_back(i);
		stk.push_back(i);
	}
	for (stk.clear(), i = n; i > 0; --i) {
		while (stk.size() && h[stk.back()] < h[i])
			stk.pop_back();
		if (stk.size())
			to[i].push_back(stk.back());
		stk.push_back(i);
	}
	for (stk.clear(), i = n; i > 0; --i) {
		while (stk.size() && h[stk.back()] > h[i])
			stk.pop_back();
		if (stk.size())
			to[i].push_back(stk.back());
		stk.push_back(i);
	}
	for (i = 1; i <= n; ++i) {
		for (auto nxt : to[i]) {
			if (d[nxt]<0 || d[nxt]>d[i] + 1)
				d[nxt] = d[i] + 1;
		}
	}
	printf("%d",d[n]);
	return 0;
}