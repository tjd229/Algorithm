//string, AC
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int cnt;
vector<int> stk;
int valid[600060];
int pi[600060];
int tail[600060];
int nxt[600060][26];
int rt1[20], rt2[20];
vector<int> node1[20], node2[20];
vector<int> D1[20], D2[20];
string s[300000];
int get_ix() {
	int ix;
	if (stk.size()) {
		ix = stk.back();
		stk.pop_back();
	}
	else ix = cnt++;
	return ix;
}
void make_trie(int rt, string &s, vector<int> &nodes) {
	int cur = rt;
	for (auto c : s) {
		int ic = c - 'a';
		if (nxt[cur][ic] == 0) {
			int node = nxt[cur][ic] =get_ix();
			pi[node] = rt; valid[node] = 0; tail[node] = 0;
			for (int i = 0; i < 26; ++i) nxt[node][i] = 0;
			nodes.push_back(node);
		}
		cur = nxt[cur][ic];
	}
	valid[cur] = 1;
}
void set_pi(int rt, vector<int> &nodes) {
	queue<int> q; q.push(rt);
	while (q.size()) {
		int cur = q.front(); q.pop();
		tail[cur] = tail[pi[cur]] + valid[cur];
		for (int i = 0; i < 26; ++i) {
			if (nxt[cur][i]) {
				int p = pi[cur];
				while (p != rt && nxt[p][i] == 0) p = pi[p];
				if (nxt[cur][i] != nxt[p][i]) {
					pi[nxt[cur][i]] = nxt[p][i] ? nxt[p][i] : rt;
				}
				q.push(nxt[cur][i]);
			}
		}
	}
	//fast_link
	for (auto x : nodes) {
		for (int i = 0; i < 26; ++i) {
			if (nxt[x][i] == 0)
				nxt[x][i] = nxt[pi[x]][i];
		}
	}
}
void mv(vector<int> &src,vector<int> &dst) {
	while (src.size()) {
		dst.push_back(src.back());
		src.pop_back();
	}
}
void mk_AC(int &rt, vector<int> &D, vector<int> &nodes) {
	rt = get_ix();
	pi[rt] = rt; valid[rt] = 0; tail[rt] = 0;
	for (int i = 0; i < 26; ++i) nxt[rt][i] = 0;
	nodes.push_back(rt);
	for (auto six : D) make_trie(rt, s[six], nodes);
	set_pi(rt, nodes);
}
void add(int six,int *rt,vector<int> *D,vector<int> *node) {
	vector<int> v = { six };
	for (int i = 0; i < 20; ++i) {
		if (D[i].size()) {
			mv(node[i],stk);
			mv(D[i], v);			
		}
		else {
			D[i] = v;
			mk_AC(rt[i], D[i], node[i]);
			break;
		}
	}
}
int search(int rt,string &s) {
	int res = 0;
	int cur = rt;
	for (auto c : s) {
		int ic = c - 'a';
		while (cur != rt && nxt[cur][ic] == 0) cur = pi[cur];
		cur = nxt[cur][ic]? nxt[cur][ic]:rt;
		res += tail[cur];
	}
	return res;
}
int search(string &s, int *rt, vector<int> *D) {
	int res = 0;
	for (int i = 0; i < 20; ++i) {
		if (D[i].size())
			res += search(rt[i], s);
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cnt = 1;
	
	int i, m; cin >> m;
	for (i = 0; i < m;++i) {
		int t; cin >> t;
		if (t == 1) {
			cin >> s[i];
			add(i, rt1, D1, node1);
		}
		else if (t == 2) {
			cin >> s[i];
			add(i, rt2, D2, node2);
		}
		else {
			cin >> s[i];
			int ans = search(s[i],rt1, D1) - search(s[i],rt2, D2);
			cout << ans << endl;
		}
	}

	return 0;
}