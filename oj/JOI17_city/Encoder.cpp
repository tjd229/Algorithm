//graph, math
#include "Encoder.h"
#include <vector>
using namespace std;
vector<int> edge[250000];
vector<int> range;
int in[250000],p[250000];
int cnt;
void dfs(int x,int from) {
	in[x] =cnt++;
	for (auto to : edge[x]) {
		if (to == from) continue;
		dfs(to, x);
	}
	if (in[x] == cnt - 1) return;
	int &e=p[x];
	while (in[x] + range[e] < cnt - 1) ++e;
	
	cnt = in[x] + range[e] + 1;
}
void Encode(int N, int A[], int B[])
{
	//const double r = 1.055645;
	const double r = 1.026056;
	range.push_back(0);
	for (int i = 1;i<512; ++i) {
		int ar = r * range.back();
		if (range.back() == ar) ++ar;
		range.push_back(ar);
	}

	for (int i = 0; i < N-1; ++i) {
		edge[B[i]].push_back(A[i]);
		edge[A[i]].push_back(B[i]);
	}
	dfs(0,-1);
	for (int i = 0; i < N ; ++i) 
		Code(i, in[i] + (p[i] << 19));
	
}
