//graph
#include "Anthony.h"
#include <vector>
#include <queue>

namespace {

	std::vector<int> edge[20000];
	int d[20000], m[20000];
	bool inq[20000];

	const int pat[6] = { 1,0,1,1,0,0 };

	void dfs(int x, int from) {

		if (x > 0 && edge[x].size() > 2) {//junction
			if (pat[m[from]] == 1) m[x] = 1;
			else m[x] = 0;
		}
		int nxtm = (m[x] + 1) % 6;
		for (auto nxt : edge[x]) {
			if (nxt == from) continue;
			d[nxt] = 1 + d[x];
			m[nxt] = nxtm;
			dfs(nxt, x);
		}
	}
	void bfs(int src) {
		std::queue<int> q; q.push(src);
		inq[src] = 1;
		while (q.size()) {
			int x = q.front(); q.pop();
			for (auto nxt : edge[x]) {
				if (inq[nxt]) continue;
				d[nxt] = d[x] + 1;
				q.push(nxt); inq[nxt] = 1;
			}
		}
	}

}  // namespace

std::vector<int> Mark(int N, int M, int A, int B,
	std::vector<int> U, std::vector<int> V) {
	for (int i = 0; i < M; ++i) {
		int u = U[i], v = V[i];
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	std::vector<int> X;
	if (B) {//tree
		dfs(0, 0);

		for (int i = 0; i < M; ++i) {
			int u = U[i], v = V[i];
			if (d[u] > d[v]) u ^= v ^= u ^= v;
			X.push_back(pat[m[u]]);
		}
	}

	else {
		bfs(0);
		for (int i = 0; i < M; ++i) {
			int u = U[i], v = V[i];
			if (d[u] > d[v]) u ^= v ^= u ^= v;
			X.push_back(d[u] % 3);
		}
	}
	return X;
}
