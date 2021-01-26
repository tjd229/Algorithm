//math, line sweeping
#include "vision.h"
#include <algorithm>
using namespace std;
void network_K(int K, vector<int> &pos, vector<int> &suf, vector<int> &all) {
	for (int i = 0; i + K < 400; ++i) {
		if (pos[i] < 0 || suf[i + K] < 0) continue;
		all.push_back(add_and({ pos[i],suf[i + K] }));
	}
}
void construct_network(int H, int W, int K) {
	vector<int> X[400], Y[400], all;
	vector<int> xpos(400, -1), ypos(400, -1);
	vector<int> xsuf(400, -1), ysuf(400, -1);
	vector<int> rx, ry;
	int pad = H - 1;
	int ix = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			int nx = j - i + pad;
			int ny = j + i;
			Y[ny].push_back(ix);
			X[nx].push_back(ix++);
		}
	}
	int lastx = -1, lasty = -1;
	for (int i = 399; i >= 0; --i) {
		if (X[i].size()) {
			xpos[i] = add_or(X[i]);
			if (lastx < 0) 
				lastx=xsuf[i] = xpos[i];
			else lastx = xsuf[i] = add_or({ xpos[i],lastx });
		}
		if (Y[i].size()) {
			ypos[i] = add_or(Y[i]);
			if (lasty < 0)
				lasty = ysuf[i] = ypos[i];
			else lasty = ysuf[i] = add_or({ypos[i],lasty });
		}
	}
	network_K(K, xpos, xsuf, all); network_K(K, ypos, ysuf, all);
	int last = add_or(all);
	
	if (K < H + W - 2) {
		all.clear();
		network_K(K + 1, xpos, xsuf, all); network_K(K + 1, ypos, ysuf, all);
		add_xor({ last,add_or(all) });
	}
}