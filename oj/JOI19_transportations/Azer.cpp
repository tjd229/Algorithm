//graph, dijkstra
#include "Azer.h"
#include <vector>
#include <queue>
#define pii std::pair<int,int>
#define vec std::vector<pii >
#define pq std::priority_queue<pii >
namespace {

int N;
int vis[2000];
vec edge[2000];
int d[2000];
int buf[20];
int sz, r;
pq q;
int recon() {
	int n = 0;
	for (int i = 0; i < sz; ++i) 
		n += n + buf[i];
	return n;
}
}  // namespace
void _SendA(int n,int k) {
	while (k--) {
		SendA(n&1);
		n >>= 1;
	}
}

void InitA(int N, int A, std::vector<int> U, std::vector<int> V,
           std::vector<int> C) {
	::N = N;
	for (int i = 0; i < A; ++i) {
		edge[U[i]].push_back({V[i],C[i]});
		edge[V[i]].push_back({ U[i],C[i] });
	}
	for (int i = 0; i < N; ++i) q.push({ -1e9,i }), d[i] = 1e9;
	vis[0] = 1; d[0] = 0;
	for (auto p : edge[0]) {
		int v = p.first;
		int c = p.second;
		d[v] = c;
		q.push({-d[v],v});
	}
	int da=-q.top().first;
	if (da > 500) da = 510;
	_SendA(da, 9); sz = r = 9;
	buf[18] = 0;
}

void ReceiveA(bool x) {
	buf[--r]=x;
	if (r == 0) {
		int v;
		if (sz == 9) {
			int db = recon();
			v = q.top().second;
			int da = d[v] - d[buf[18]];
			if (da <= db) {
				_SendA(v,11);
				q.pop();
				//go inq
			}
			else {
				buf[19] = db;
				r = sz = 11;
				return;
			}
		}
		else {//sync v
			v= recon();
			d[v] = d[buf[18]] + buf[19];
			//go inq
		}
		//inq
		vis[v] = 1;
		for (auto p : edge[v]) {
			int nxt = p.first;
			int c = p.second;
			if (d[nxt] > d[v] + c) {
				d[nxt] = d[v] + c;
				q.push({ -d[nxt],nxt });
			}
		}
		while (q.size() && vis[q.top().second]) q.pop();//q empty chk??
		if (q.size()) {
			int da = -q.top().first;
			int diff = da - d[v];
			if (diff > 500) diff = 510;
			_SendA(diff, 9);
			r = sz = 9;
			buf[18] = v;
		}
	}
}

std::vector<int> Answer() {
  std::vector<int> ans(N);
  for (int i = 0; i < N; ++i) ans[i] = d[i];
  return ans;
}
