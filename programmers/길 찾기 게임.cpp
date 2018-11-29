//https://www.welcomekakao.com/learn/courses/30/lessons/42892
//graph
#include <string>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
vector<pii > node[1001];
int edge[10001][2];
int l[10001], r[10001];
int x[10001];
void pre(int ix,vector<int> &record) {
	record.push_back(ix);
	for(int i=0;i<2;++i)
		if (edge[ix][i]) pre(edge[ix][i], record);
}
void post(int ix, vector<int> &record) {
	for (int i = 0; i < 2; ++i)
		if (edge[ix][i]) post(edge[ix][i], record);
	record.push_back(ix);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer(2);
	vector<pii > v;
	int depth = 0;
	int N = nodeinfo.size();
	for (int i = 0; i < N; ++i) {
		v.push_back({-nodeinfo[i][1],i});
		x[i + 1] = nodeinfo[i][0];
	}
	sort(v.begin(), v.end());
	int piv = v[0].first;
	for (int i = 0; i < N; ++i) {
		if (piv != v[i].first) {
			++depth;
			piv = v[i].first;
		}
		int ix = v[i].second+1;
		node[depth].push_back({x[ix],ix});
	}
	int root = node[0][0].second;
	l[root] = 0;
	r[root] = 1e5;
	for (int i = 1; i <= depth; ++i) {
		auto p = node[i - 1].begin();
		sort(node[i].begin(), node[i].end());
		
		for (int j = 0; j < node[i].size();) {
			int ix = node[i][j].second;
			
			if (l[p->second] <= x[ix] && x[ix] < p->first) {
				edge[p->second][0] = ix;
				l[ix] = l[p->second];
				r[ix] = p->first;
				++j;
			}
			else if (p->first < x[ix] && x[ix] <= r[p->second]) {
				edge[p->second][1] = ix;
				r[ix] = r[p->second];
				l[ix] = p->first;
				++j;
			}
			else ++p;
		}
	}
	pre(root, answer[0]);
	post(root, answer[1]);
	return answer;
}
