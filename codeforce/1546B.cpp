//string
#include <iostream>
#include <string>
using namespace std;
string s[100000];
int cnt[100000][26];
int init_cnt[100000][26];
int n, m;
bool cmp() {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (cnt[i][j] != init_cnt[i][j]) return 0;
		}
	}
	return 1;
}
void init() {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 26; ++j) {
			cnt[i][j] = init_cnt[i][j] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, j; cin >> n >> m;
		for (i = 0; i < n; ++i) {
			cin >> s[i];
			for (j = 0; j < m; ++j) ++init_cnt[j][s[i][j] - 'a'];
		}
		for (i = 1; i < n; ++i) {
			string st; cin >> st;
			for (j = 0; j < m; ++j)
				++cnt[j][st[j] - 'a'];
		}
		for (i = 0; i <= n; ++i) {
			for (j = 0; j < m; ++j)
				--init_cnt[j][s[i][j] - 'a'];
			if (cmp()) {
				cout << s[i] << endl;
				break;
			}
			for (j = 0; j < m; ++j)
				++init_cnt[j][s[i][j] - 'a'];
		}
		init();
	}
	return 0;
}