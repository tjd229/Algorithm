//graph, math
#include "Alicelib.h"
#include <cassert>
#include <cstdio>
#include <vector>
#define pii pair<int,int>
using namespace std;
void Alice( int N, int M, int A[], int B[] ){
	vector<pii > ex;
	int is = N + 10;
	int d1 = is + 1;
	for (int i = 0; i < N; ++i) {
		ex.push_back({ is,i });
		int ix = 1 + i;
		for (int k = 0; k < 10 && ix; ++k,ix>>=1) {
			if (ix & 1) ex.push_back({ N + k,i });
		}
	}
	for (int i = 1; i < 10; ++i) ex.push_back({N+i-1,N+i});
	ex.push_back({ is,d1 });
	InitG(N+12,M+ex.size());
	for (int i = 0; i < M; ++i) MakeG(i,A[i],B[i]);
	for (int i = 0; i < ex.size(); ++i) MakeG(M+i,ex[i].first,ex[i].second);
}

