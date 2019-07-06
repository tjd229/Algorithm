//graph
#include "Anyalib.h"
#include <vector>
using namespace std;
int _N;
int u[500], v[500];
int h;
vector<int> eix[500];
//L<-road|hub
int to(int src,int eix) {
	if (u[eix] == src) return v[eix];
	return u[eix];
}
int dfsa(int x,int from,int s,int *C) {
	int len = 0;
	for (auto ix : eix[x]) {
		int dst = to(x,ix);
		if (from == dst) continue;
		if (C[ix]) Save(999-dst,1);
		int dist = dfsa(dst,x,s+C[ix],C);
		if (len < dist) len = dist;
	}
	++len;
	if (x && len > 11) {//hub
		int pos = h * 9;
		while (s) {
			Save(pos++,s&1);
			s >>= 1;
		}
		len = 0;
		++h;
	}
	return len;
}
void InitAnya(int N , int A[] , int B[]) {
	_N = N;
	for (int i = 0; i < N - 1; ++i) {
		u[i] = A[i], v[i] = B[i];
		eix[A[i]].push_back(i);
		eix[B[i]].push_back(i);
	}
}

void Anya(int C[]) {
	h = 0;
	dfsa(0,-1,0,C);
}
