//trie

#include <iostream>
#include <string>
using namespace std;
int node[100001];
int nxt[100001][10];
int cnt;
bool make_trie(string &s) {
	int curr = 0;
	for (auto c : s) {
		c = c - '0';
		if (nxt[curr][c] == 0) {
			++cnt;
			for (int i = 0; i < 10; ++i) nxt[cnt][i] = 0;
			nxt[curr][c] = cnt;
			node[cnt] = 0;
		}
		curr = nxt[curr][c];
		if (node[curr]) return false;
	}
	node[curr] = 1;
	for (int i = 0; i < 10; ++i) if (nxt[curr][i]) return false;
	return true;
}
int main() {
	int t;
	int n, i;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		bool flag = true;
		cnt = 0;
		for (i = 0; i < 10; ++i) nxt[0][i] = 0;
		for (i = 0; i < n; ++i) {
			string pn;
			cin >> pn;
			flag &= make_trie(pn);
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}

	return 0;
}
