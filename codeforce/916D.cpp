//string, trie, pst
#include <iostream>
#include <string>
using namespace std;
const int LEAF = 1 << 30;
int st[6200001],l[6200001],r[6200001];
int st_root[100001],trie_root[100001];
int nxt[1600002][26];
int trie[1600002];
int priority[1600002];

int trie_node,st_node;
int make_trie(int pre,string &s,int ix,int p) {
	int cur = ++trie_node;
	int rt = cur;
	for (int i = 0; i < 26; ++i) nxt[cur][i] = nxt[pre][i];
	for (auto c : s) {
		int ic = c - 'a';
		nxt[cur][ic] = ++trie_node;
		cur = nxt[cur][ic];
		if (pre>=0 &&nxt[pre][ic]) {
			pre = nxt[pre][ic];
			trie[cur] = trie[pre];
			priority[cur] = priority[pre];
			for (int i = 0; i < 26; ++i) nxt[cur][i] = nxt[pre][i];
		}	
		else pre = -1;
	}
	trie[cur] = ix;
	priority[cur] = p;
	return rt;
}
int trie_leaf(int rt,string &s) {
	int cur = rt;
	for (auto c : s) {
		int ic = c - 'a';
		if (nxt[cur][ic] == 0)
			return 0;
		cur = nxt[cur][ic];
	}
	return cur;
	//return s2ix[cur];
}
int make_tree(int pre,int s,int e,int pos,int d) {
	if (e < pos || pos < s) return pre;
	int ix = ++st_node;
	if (s == e && s==pos)
		st[ix] = st[pre] + d;
	else {
		l[ix] = make_tree(l[pre], s, (s + e) >> 1, pos,d);
		r[ix] = make_tree(r[pre], 1+ ((s + e) >> 1),e, pos,d);
		st[ix] = st[l[ix]] + st[r[ix]];
	}
	return ix;
}
int sum(int ix,int s,int e,int from,int to) {
	if (e < from || to < s) return 0;
	if (from <= s && e <= to) return st[ix];
	return sum(l[ix], s, (s + e) >> 1, from, to) + sum(r[ix], ((s + e) >> 1) + 1, e, from, to);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, q; cin >> q;
	int atot = 0;
	for(i=1;i<=q;++i) {
		string op, a; int x; cin >> op;
		if (op[0] == 's') {
			cin >> a>>x;
			trie_root[i] = trie_root[i - 1];
			st_root[i] = st_root[i - 1];
			int leaf = trie_leaf(trie_root[i], a);
			int aix = trie[leaf];
			if(aix>0)
				st_root[i] = make_tree(st_root[i], 0, LEAF - 1, priority[leaf], -1);
			aix = ++atot;
			trie_root[i] = make_trie(trie_root[i], a, aix, x);
			st_root[i] = make_tree(st_root[i], 0, LEAF - 1, x, 1);

		}
		else if (op[0] == 'r') {
			cin >> a;
			trie_root[i] = trie_root[i - 1];
			st_root[i] = st_root[i - 1];
			int leaf = trie_leaf(trie_root[i], a);
			if (trie[leaf] > 0) {
				st_root[i] = make_tree(st_root[i], 0, LEAF - 1, priority[leaf], -1);
				trie_root[i] = make_trie(trie_root[i], a, 0,0);
			}
		}
		else if (op[0] == 'q') {
			cin >> a;
			trie_root[i] = trie_root[i - 1];
			st_root[i] = st_root[i - 1];
			int leaf = trie_leaf(trie_root[i], a);
			if (trie[leaf] == 0)
				cout << "-1"<<endl;
			else {
				int x = priority[leaf];
				//cout << x << endl;
				cout << sum(st_root[i], 0, LEAF - 1, 0, x - 1) << endl;
			}
		}
		else {
			int d; cin >> d;
			st_root[i] = st_root[i -1- d];
			trie_root[i] = trie_root[i - 1 - d];
		}
	}
	return 0;
}