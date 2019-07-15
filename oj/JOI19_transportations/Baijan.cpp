//graph, dijkstra
#include "Baijan.h"
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
	int sz, r;
	int buf[20];
	pq q;
	int recon() {
		int n = 0;
		for (int i = 0; i < sz; ++i) n += n + buf[i];
		return n;
	}
}  // namespace
void _SendB(int n, int k) {
	while (k--) {
		SendB(n & 1);
		n >>= 1;
	}
}
void InitB(int N, int B, std::vector<int> S, std::vector<int> T,
           std::vector<int> D) {
	::N = N;
	for (int i = 0; i < B; ++i) {
		edge[S[i]].push_back({T[i],D[i]});
		edge[T[i]].push_back({ S[i],D[i] });
	}
	for (int i = 0; i < N; ++i) q.push({ -1e9,i }), d[i] = 1e9;
	vis[0] = 1; d[0] = 0;
	for (auto p : edge[0]) {
		int v = p.first;
		int c = p.second;
		d[v] = c;
		q.push({ -d[v],v });
	}
	int db = -q.top().first;
	if (db > 500) db = 510;
	_SendB(db, 9); sz = r = 9; buf[18] = 0;
}

void ReceiveB(bool y) {
	buf[--r] = y;
	if (r == 0) {
		int v;
		if (sz == 9) {
			int da = recon();
			v = q.top().second;
			int db = d[v]-d[buf[18]];
			if (da > db) {
				_SendB(v, 11);
				q.pop();
				//go inq
			}
			else {
				buf[19] = da;
				r = sz = 11;
				return;
			}
		}
		else {//sync v
			v = recon();
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
			int db = -q.top().first;
			int diff = db - d[v];
			if (diff > 500) diff = 510;
			_SendB(diff, 9);
			r = sz = 9;
			buf[18] = v;
		}
	}
}
