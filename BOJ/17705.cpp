//implementaion
#include "Memory2_lib.h"
#include <vector>
#define pii pair<int,int>
using namespace std;
vector<pii > v[50];
void Solve(int T, int N){
	int NN = N + N;
	for (int i = 0; i < NN; i += 2) {
		v[Flip(i, i + 1)].push_back({i,i+1});
	}
	for (int find = 0; find < N; ++find) {
		bool deg=1;
		for (int i = 0; deg &&i < N; ++i) {
			if (v[i].size() == 2) {
				deg = 0;
				int a = v[i].back().first, b = v[i].back().second;
				v[i].pop_back();
				int c = v[i].back().first, d = v[i].back().second;
				v[i].pop_back();
				int ac = Flip(a, c), bd = Flip(b, d);
				if (ac == i && bd != i);
				else if (ac != i && bd == i) {
					a ^= b ^= a ^= b;
					c ^= d ^= c ^= d;
				}
				else {
					c ^= d ^= c ^= d;
					ac = Flip(a, c), bd = Flip(b, d);
					if (ac != i && bd == i) {
						a ^= b ^= a ^= b;
						c ^= d ^= c ^= d;
					}
				}
				Answer(a,c,i);
				v[Flip(b, d)].push_back({b,d});
			}
		}
		//deg
		if (deg) {
			for (int i = 0; i < N; ++i) {
				for (auto p : v[i])
					Answer(p.first, p.second, i);
			}
			find = N;
		}
	}
	return;
}