//graph, math
#include "Boblib.h"
#include <cassert>
#include <cstdio>
#include <vector>
#include <deque>
#define pii pair<int,int>
using namespace std;
vector<int> edge[1012];
int ix[1012];
void Bob( int V, int U, int C[], int D[] ){
	int N = V - 12;
	int d1, is;
	vector<pii > ans;
	vector<int> info;
	deque<int> dq;
	for (int i = 0; i < U; ++i) {
		edge[C[i]].push_back(D[i]);
		edge[D[i]].push_back(C[i]);
	}
	for (int i = 0; i < V; ++i) {
		if (edge[i].size() == 1) {
			int candi = edge[i][0];
			if (edge[candi].size() == N + 1) {
				d1 = i;
				is = candi;
			}
		}
	}
	ix[is] = 1;
	for (auto dst : edge[is]) 
		ix[dst] = 1;
	
	
	for (int i = 0; i < V && dq.empty(); ++i) {
		if (ix[i] == 0) dq.push_back(i),ix[i]=-1;
	}
	
	//return;
	while (dq.size() < 10) {
		int i = dq.front();
		for (auto to : edge[i]) {
			if (ix[to] == 0) {
				dq.push_front(to);
				ix[to] = -1;//in q
				break;
			}
		}
		i = dq.back();
		for (auto to : edge[i]) {
			if (ix[to] == 0) {
				dq.push_back(to);
				ix[to] = -1;
				break;
			}
		}
	}
	while (dq.size()) info.push_back(dq.front()),dq.pop_front();


	if (edge[info.back()].size() == (N >> 1) + (N & 1)+1) {
		for (int i = 0; i < 5; ++i)
			info[i] ^= info[9 - i]^= info[i] ^= info[9 - i];
	}
	ix[is] = ix[d1] = -1;
	for (int i = 0; i < V; ++i) if(ix[i]>=0) ix[i] = 0;	
	for (int i = 0; i < info.size(); ++i) {
		for (auto to : edge[info[i]]) {
			if(ix[to]>=0)
				ix[to] += (1 << i);
		}
	}
	for (int i = 0; i < U; ++i) {
		if (ix[C[i]] > 0 && ix[D[i]] > 0) {
			ans.push_back({ix[C[i]]-1, ix[D[i]]-1});
		}
	}

	InitMap(N,ans.size());
	for (auto e : ans)
		MakeMap(e.first,e.second);
}

