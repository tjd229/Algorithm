//https://programmers.co.kr/learn/courses/30/lessons/72413
//graph, floyd
#include <string>
#include <vector>

using namespace std;
const int inf = 1e8;
int d[201][201];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j) d[i][j] = inf;
	for (auto edge : fares) {
		int u = edge[0], v = edge[1], w = edge[2];
		d[u][v] = d[v][u] = w;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				if (d[j][i] == inf || d[i][k] == inf) continue;
				if ( d[j][k] > d[j][i] + d[i][k])
					d[j][k] = d[j][i] + d[i][k];
			}
		}
	}

	for (int i = 1; i <= n; ++i) d[i][i] = 0;
	answer = d[s][a] + d[s][b];
	for (int i = 1; i <= n; ++i) {
		if (i == s) continue;
		if (answer > d[s][i] + d[i][a] + d[i][b])
			answer = d[s][i] + d[i][a] + d[i][b];
	}
	return answer;
}