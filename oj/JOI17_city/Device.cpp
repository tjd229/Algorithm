//graph, math
#include "Device.h"
#include <vector>
using namespace std;
vector<int> a;
void InitDevice()
{
	const double r = 1.026056;
	a.push_back(0);
	for (int i = 1; i < 512; ++i) {
		int ar = a.back()*r;
		if (a.back() == ar)++ar;
		a.push_back(ar);
	}
}

int Answer(long long S, long long T)
{
	int ss = S & ((1 << 19) - 1);
	int ts= T & ((1 << 19) - 1);
	int se = ss+a[S >> 19];
	int te = ts+a[T >> 19];
	if (ss <= ts && te <= se) return 1;
	if (ts <= ss && se <= te) return 0;
	return 2;
}
