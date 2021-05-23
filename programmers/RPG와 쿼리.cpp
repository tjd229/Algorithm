//https://programmers.co.kr/learn/courses/30/lessons/76504
//graph, math
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#define pii pair<int,int>
using namespace std;
const int inf = 2e9;
int zz;
int cnt[3000][3000];//[vtx][cost]
int mncnt[3000];
int vis[3000];//[cost]
vector<pii > edge[3000];
vector<long long> solution(int n, int z, vector<vector<int>> roads, vector<long long> queries) {
	vector<long long> answer;
	zz = z * z;
	for (int i = 0; i < roads.size(); ++i) {
		int u = roads[i][0], v = roads[i][1], w = roads[i][2];
		edge[u].push_back({ v,w });
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= zz; ++j) cnt[i][j] = inf;
	}
	queue<pii > q; q.push({ 0,0 });
	cnt[0][0] = 0;
	while (q.size()) {
		int x, w; tie(x, w) = q.front();
		q.pop();
		if (vis[w] == 0) {
			vis[w] = 1;
			for (int i = 0; i < n; ++i) {
				if (cnt[x][w] + 1 < cnt[i][w]) {
					cnt[i][w] = cnt[x][w] + 1;
					q.push({ i,w });
				}
			}
		}
		for (auto p : edge[x]) {
			int v, weight; tie(v, weight) = p;
			int nxtw = weight + w;
			if (nxtw <= zz && cnt[v][nxtw] > cnt[x][w] + 1) {
				cnt[v][nxtw] = cnt[x][w] + 1;
				q.push({ v,nxtw });
			}
		}
	}
	for (int j = 0; j <= zz; ++j) {
		mncnt[j] = cnt[0][j];
		for (int i = 1; i < n; ++i) {
			if (mncnt[j] > cnt[i][j]) mncnt[j] = cnt[i][j];
		}
	}
	for (long long q : queries) {
		if (q == 0) answer.push_back(0);
		else {
			int coin = 51;
			long long ans = -1;
			long long d = q / z;
			int r = q % z;
			while (coin--) {
				long long cnt = d;
				if (mncnt[r] == inf) cnt = -1;
				else cnt += mncnt[r];
				if (cnt != -1) {
					if (ans<0 || ans>cnt) ans = cnt;
				}
				--d;
				r += z;
				if (r > zz) break;
				if (d < 0) break;
			}
			answer.push_back(ans);
		}
	}
	return answer;
}