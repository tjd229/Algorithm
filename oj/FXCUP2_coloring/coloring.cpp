//bs
#include "coloring.h"
#include <vector>
using namespace std;
bool in[101];
vector<int> v1, v2;
int paint = 0;
int find(int back, int &coin) {
	if (v1.size() == 1 && v2.empty()) return v1[0];
	else if (v2.size() == 1 && v1.empty()) return v2[0];
	if (!coin) return -1;
	for (auto x : v1) Color(x), ++paint;
	int c = GetColor(back); --coin;
	vector<int> *live = &v1, *erase = &v2;
	if (c) live = &v2, erase = &v1;

	erase->clear();
	while (live->size() > erase->size()) {
		erase->push_back(live->back());
		live->pop_back();
	}
	return find(back, coin);
}
void ColoringSame(int N) {
	int i;
	int coin = 200;
	vector<int> stk, v;
	stk.push_back(1);
	while (coin>6 && stk.size()!=N) { // N cond
		int t = 1;
		v1.clear(); v2.clear();
		for (i = 2; i <= N; ++i) {
			if (in[i]) continue;
			if (t) v1.push_back(i);
			else v2.push_back(i);
			t = 1 - t;
		}
		int back = find(stk.back(), coin);
		if (back > 0) {
			in[back] = 1;
			stk.push_back(back);
		}
		else break;

	}
	for (Color(1), i = 2; i <= N; ++i) { if (!in[i]) v.push_back(i); }
	int pad = 0;
	for (i = 0; i < v.size() && paint+stk.size()<7300; ++i) {
		//if (i == 1) pad += 1;
		//else if (i == 5) pad+=2;
		for (int j = 0; j < v.size() && paint + stk.size() < 7300; ++j)
			Color(v[j]),++paint;
	}
	for (; stk.size() > 1; stk.pop_back()) Color(stk.back());
}