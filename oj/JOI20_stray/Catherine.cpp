//graph
#include "Catherine.h"
#include <vector>

namespace {
	int _B;
	int _A;
	std::vector<int> hist;
	const int pat[6 + 6] = { 1,0,1,1,0,0 ,1,0,1,1,0,0 };//dn dir
	int mv = 0;
	bool dir = 0;
}  // namespace

void Init(int A, int B) {
	_A = A, _B = B;
}
int soft_move(std::vector<int> &y) {
	if (dir) {
		if (y[0] + y[1] > 1) {
			int prev = hist.back();
			++y[prev];
			int nxt = y[0] == 1 ? 0 : 1;
			hist.push_back(nxt);
		}
		else {
			int nxt = y[0] ? 0 : 1;
			hist.push_back(nxt);
		}
		return hist.back();
	}
	else {
		if (mv == 0) {//init
			if (y[1]==1 &&y[0] == 0) {//leaf
				dir = 1;
				hist.push_back(1);
				return 1;
			}
			else if (y[0] == 1 && y[1] == 0) {//leaf
				dir = 1;
				hist.push_back(0);
				return 0;
			}
			else if (y[0] + y[1] > 2) {//junc
				dir = 1;
				int nxt = y[0] == 1 ? 0 : 1;
				hist.push_back(nxt);
				return nxt;
			}
			while (y[0]--) hist.push_back(0);//1-way
			while (y[1]--) hist.push_back(1);
			++mv;
			return hist.back();
		}
		else if (y[0] + y[1] == 0) {//leaf;
			dir = 1;
			hist.push_back(hist.back());
			return -1;
		}
		else if (y[0] + y[1] > 1) {//junc 
			int prev = hist.back();
			int nxt = 1 - prev;
			dir = 1;

			if (y[nxt] == 1) {
				hist.push_back(nxt);
				return nxt;
			}
			else {
				hist.push_back(prev);
				return -1;
			}
		}
		else {//way
			int nxt = y[0] ? 0 : 1;
			if (mv++ == 3) {
				hist.push_back(nxt);
				dir = 1;
				for (int s = 0; s < 6; ++s) {
					bool flag = 1;
					for (int i = 0; i < 5 && flag; ++i) {
						if (hist[i] != pat[s + i]) flag = 0;
					}
					if (flag) {
						hist.pop_back();
						hist.push_back(hist.back());
						return -1;
					}
				}
				hist.push_back(nxt);
				return hist.back();
			}
			else {
				hist.push_back(nxt);
				return hist.back();
			}
		}
	}
}
int hard_move(std::vector<int> &y) {
	if (y[0] == 0 && y[1]) return 1;
	else if (y[1] == 0 && y[2]) return 2;
	else return 0;
}
int Move(std::vector<int> y) {
	if (_B) return soft_move(y);
	else return hard_move(y);
}
