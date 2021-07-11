//https://programmers.co.kr/learn/courses/30/lessons/81305
//graph, dp, bs
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> *edge;
vector<int> *app;
int d[10000], tot[10000];
int call[10000];
void sim(int x,int cap) {
	d[x] = 1; tot[x] = app[0][x];
	int l = edge[0][x][0], r = edge[0][x][1];
	int l_group = 0, r_group = 0;
	int l_tot = 1e9, r_tot = 1e9;
	if (l != -1) {
		sim(l, cap);
		l_group = d[l];
		l_tot = tot[l];
	}
	if (r != -1) {
		sim(r, cap);
		r_group = d[r]; r_tot = tot[r];
	}
	if (tot[x] + r_tot + l_tot <= cap) {
		d[x] = l_group + r_group - 1;
		tot[x] += r_tot + l_tot;
	}
	else if (tot[x] + r_tot<=cap || tot[x] + l_tot<=cap) {
		d[x] = l_group + r_group;
		tot[x] += min(r_tot, l_tot);
	}
	else {
		d[x] += l_group + r_group;
	}
}
int solution(int k, vector<int> num, vector<vector<int>> links) {
	int answer = 0;
	int l=0,r = 0;
	edge = &links; app = &num;
	for (int i = 0; i < num.size(); ++i) {
		int u = links[i][0], v = links[i][1];
		if (u != -1) call[u] = 1;
		if (v != -1) call[v] = 1;
	}
	int rt=-1;
	for (int i = 0;rt==-1 &&  i < num.size(); ++i) {
		if (call[i] == 0) rt = i;
	}
	for (auto x : num) r += x, l=max(l,x);
	l = max(l,r / k);
	while (l <= r) {
		int m = (l + r) >> 1;
		sim(rt, m);
		if (d[rt] <= k) r = m - 1,answer=m;
		else l = m + 1;
	}

	return answer;
}