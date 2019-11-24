//graph, bs

#include <iostream>
#include <string>
#include <vector>
#define pii pair<int,int>
using namespace std;
string mp[1000001];
string X[1000001],Y[1000001];
vector<int > s[1000001];
int n, m;
void init(string *mp) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m; ++j) {
			mp[i][j] = '.';
		}
	}
}
void deconv(int sz,string *mp) {
	int sq = (sz+sz+1)*(sz + sz + 1);
	for (int i = 1 + sz; i + sz <= n; ++i) {
		for (int j = 1 + sz; j + sz <= m; ++j) {
			int sx = j - sz, sy = i - sz;
			int ex = j + sz, ey = i + sz;
			int sum = s[ey][ex] - s[sy - 1][ex] - s[ey][sx - 1] + s[sy-1][sx-1];
			if (sum == sq) {
				mp[i][j - 1] = 'X';
			}
		}
	}
}
void bfs(int T,string *mp) {
	vector<pii > q;
	int i, j;
	for (i = 1; i <= n; ++i) {
		for (j = 0; j < m; ++j) {
			if (mp[i][j] == 'X') {
				q.push_back({i,j});
			}
		}
	}
	for (i = j = 0; i < T; ++i) {
		int end = q.size();
		for (; j < end; ++j) {
			int y = q[j].first;
			int x = q[j].second;
			for (int dy = -1; dy <= 1; ++dy) {
				for (int dx = -1; dx <= 1; ++dx) {
					int nx = x + dx;
					int ny = y + dy;
					if (nx < 0 || ny < 1 || nx > m - 1 || ny > n) continue;
					if (mp[ny][nx] == 'X') continue;
					mp[ny][nx] = 'X';
					q.push_back({ ny,nx });
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j; cin >> n >> m;
	s[0].resize(m + 1);
	for (i = 1; i <= n; ++i) {
		cin >> mp[i];
		s[i].resize(m + 1);
		X[i].resize(m);
		for (j = 0; j <= m; ++j) s[0][j]=s[i][j]=0;
		for (j = 0; j < m; ++j) {
			if (mp[i][j] == 'X') s[i][j + 1] = 1;
		}
	}
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
		}
	}
	
	int T = 0;
	int l = 1, r = n;
	if (r > m) r = m;
	r >>= 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		init(X);
		deconv(mid, X);
		bfs(mid, X);
		bool same = 1;
		for (i = 1; i <= n && same; ++i)
			same &= (X[i] == mp[i]);
		if (same) {
			T = mid;
			l = mid + 1;
		}
		else r = mid - 1;
		
	}
	cout << T << "\n";
	if (T) {
		init(mp);
		deconv(T, mp);		
	}
	for (i = 1; i <= n; ++i)
		cout << mp[i] << "\n";
	
	return 0;
}