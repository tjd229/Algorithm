//graph
#include "Borislib.h"
#include <vector>
using namespace std;
vector<int> edge[500];
int __N;
int k,hub[500],p[500];
int dfsb(int x,int from) {
	int len = 0;
	for (auto to : edge[x]) {
		if (to == from) continue;
		int dist = dfsb(to,x);
		p[to] = x;
		if (len < dist) len = dist;
	}
	++len;
	if (x && len > 11) hub[x] = ++k,len=0;
	return len;
}
void InitBoris(int N , int A[] , int B[]) {
	__N = N;
	for (int i = 0; i < N - 1; ++i) {
		edge[A[i]].push_back(B[i]);
		edge[B[i]].push_back(A[i]);
	}
	dfsb(0, -1);
}

int Boris(int city) {
	int ans = 0;
	while (city && hub[city] == 0) {
		ans += Ask(999-city);
		city = p[city];
	}
	if (hub[city]) {
		int pos = hub[city] * 9;
		int ac = 0;
		for (int i = 0; i < 9; ++i) {
			ac += ac;
			ac += Ask(--pos);
		}
		ans += ac;
	}
	return ans;
}
