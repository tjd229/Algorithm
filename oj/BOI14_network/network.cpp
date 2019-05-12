//graph
#include "network.h"
#include <vector>
using namespace std;
vector<int> candi[1000];
int path[1000];
void findRoute (int N, int a, int b)
{
	int len = ping(a, b);
	for (int i = 1; i <= N; ++i) {
		if (a == i || b == i) continue;
		int d = ping(a, i);
		candi[d].push_back(i);
	}
	path[len] = b;
	for (int i = len-1; i >= 0; --i) {
		for (auto x : candi[i]) {
			if (ping(x, b) == 0) {
				b = x;
				path[i] = b;
				break;
			}
		}
	}
	for (int i = 0; i <= len; ++i) travelTo(path[i]);
	
}
