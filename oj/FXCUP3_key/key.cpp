//graph, bs
#include "key.h"
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int in[1001],vis[1001];
vector<int> v[1001];
void EnsureKeyInfo(int N) {
	int i,t=0;
	int stamp = 0;
	vector<int> hist[2];
	for (i = 1; i <= N; ++i) {
		TakeKey(i);
		int cnt = Explore();
		v[cnt].push_back(i);
	}

	for (auto x : v[1]) in[x] = x,hist[0].push_back(x);
	for (i = 2; i <= N; ++i) {//i=lev
		vector<int> cyc;
		for(auto x:v[i]){
			int l = 0, r = hist[t].size() - 1;
			int p = -1;
			while (l <= r) {
				int m = (l+r)>>1;
				int pred = 0; ++stamp;
				for (int j = l; j <= m; ++j) {
					int u = hist[t][j];
					TakeKey(u);
					while (stamp != vis[u]) {
						++pred;
						vis[u] = stamp;
						u = in[u];
					}
				}
				TakeKey(x);
				int cnt = Explore();
				if (cnt - pred == 1) p = m, r = m - 1;
				else l = m + 1;
				/*if (cnt - pred == 2) l = m + 1;
				else  p=m,r = m - 1;*/
				
			}
			if (p < 0) cyc.push_back(x);
			else {
				in[x] = hist[t][p];
				hist[1-t].push_back(x);
			}
		}
		
		vector<int> meta;
		int root[1001] = { 0 };
		for (auto x : cyc) {
			if (meta.empty()) meta.push_back(x);
			else {
				int l = 0, r=meta.size() - 1;
				int p = -1;
				while (l <= r) {
					int m=(l + r) >> 1;
					int pred = 0;
					for (int j = l; j <= m; ++j) TakeKey(meta[j]),pred+=i;
					TakeKey(x);
					int cnt = Explore();
					if (cnt == pred) p = m, r = m - 1;
					else l = m + 1;
				}
				if (p < 0) meta.push_back(x);
				else {
					in[x] = meta[p];
					if (!root[p]) root[p] = meta[p];
					meta[p] = x;
				}
			}
		}
		
		for (int j = 0; j < meta.size(); ++j) {
			in[root[j]] = meta[j];
			hist[1 - t].push_back(meta[j]);
		}
		hist[t].clear();
		t = 1 - t;
		//tog
	}
	for (i = 1; i <= N; ++i) printf("%d\n",in[i]);
	for (i = 1; i <= N; ++i) {
		int x = i;
		while (-i!=vis[x]) {
			Report(i, x); vis[x] = -i;
			x = in[x];
		}
	}
}
