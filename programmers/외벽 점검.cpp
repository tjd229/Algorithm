//https://programmers.co.kr/learn/courses/30/lessons/60062
//djs
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int p[15];
int len[15];
int find(int a) {
	if(p[a] != a) p[a] = find(p[a]);
	return p[a];
}
bool un(int a, int b,int d) {
	a = find(a); b = find(b);
	if (a == b) return 0;
	p[b] = a;
	len[a] += len[b]+d;
	return 1;
}
int solution(int n, vector<int> weak, vector<int> dist) {
	int ans = -1;
	int wlen = weak.size();
	int bnd = 1 << wlen;
	sort(dist.begin(), dist.end(), [](int a, int b) {
		return a > b;
	});
	for (int stat = 0; stat < bnd; ++stat) {
		int b = stat;
		for (int i = 0; i < wlen; ++i) {
			p[i] = i;
			len[i] = 0;
		}
		for (int i = 0; i < wlen; ++i) {
			if (b & 1) {
				int u = i, v = i + 1;
				int d = 0;
				if (v == wlen) {
					d = weak[0] + n - weak[u];
					//v = u;
					//u = 0;
					v = 0;
				}
				else d = weak[v] - weak[u];
				
				un(u, v, d);
			}
			b >>= 1;
		}
		vector<int> v;
		for (int i = 0; i < wlen; ++i) {
			if (i == p[i]) v.push_back(len[i]);
		}
		sort(v.begin(), v.end(), [](int a, int b) {
			return a > b;
		});
		if (v.size() <= dist.size()) {
			int cnt = v.size();
			for (int i = 0; i < v.size(); ++i) {
				if (v[i] > dist[i]) {
					cnt = 1e9;
					break;
				}
			}
			if (cnt == v.size()) {
				if (ans<0 || ans>cnt) ans = cnt;
			}
		}
	}
	return ans;
}