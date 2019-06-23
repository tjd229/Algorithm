//sqrt Decomp., bs
#include "prize.h"
#include <vector>
#define pii pair<int,int>
using namespace std;
const int seg = 446;
int pre;
int nc;//1+2+3+4
int call;
vector<int> v[200000];
void my_ask(int i) {
	if (v[i].empty()) v[i] = ask(i), ++call;
}
int search(int l, int r, int tgt) {
	int t = -1;
	while (l <= r) {
		int m = (l + r) >> 1;
		my_ask(m);
		if (v[m][0] + v[m][1] != nc) {
			t = m, r = m - 1;
			if (tgt == 1) return t;
		}
		else if (v[m][0] == pre) l = m + 1, tgt = v[m][0] - pre;
		else r = m - 1;
	}
	return t;
}
int find_best(int n) {
	if (n <= 5000) {
		for (int i = 0; i < n; ++i) {
			my_ask(i);
			if (v[i][0] + v[i][1] == 0) return i;
		}
	}
	vector<pii > g;
	int i = 0, j = seg - 1;
	int last = 0;
	while (i < n) {
		if (j >= n) j = n - 1;
		my_ask(j);
		int s = v[j][0] + v[j][1];
		if (s == 0) return j;
		if (nc < s) nc = s;
		g.push_back({ i,j });
		i += seg; j += seg;
	}
	for (i = 0; i < n && call <= 447; ++i) {
		my_ask(i);
		int s = v[i][0] + v[i][1];
		if (s == 0) return i;
		if (nc < s) nc = s;
	}
	for (; v[last].size(); ++last) {
		int s = v[last][0] + v[last][1];
		if (nc > s) ++pre;
	}
	for (i = 0; i < g.size();) {
		int e = g[i].second;
		if (last < g[i].first) last = g[i].first;
		if (e < last || (v[e][0] + v[e][1] == nc && v[e][0] == pre)) {
			++i;
			continue;
		}
		int t = search(last, e, v[e][0] - pre);
		if (v[t][0] + v[t][1] == 0) return t;
		++pre;
		last = t + 1;
	}
	return 0;
}