//dp, d&c
//https://codingcompetitions.withgoogle.com/codejam/round/0000000000877ba5/0000000000aa9280
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define pii pair<int,int>
using namespace std;
int X[101][101];
int com[101][101][101];
int cap[101][101],w[101][101];
int work(int l,int r) {
	if (w[l][r] == -1) {
		if (l == r) w[l][r] = 0;
		else {
			for (int m = l; m < r; ++m) {
				int cost = work(l, m) + work(m + 1, r);
				int stk = cap[l][m] + cap[m + 1][r] - 2 * cap[l][r];
				cost += stk + stk;
				if (w[l][r] == -1 || w[l][r] > cost) w[l][r] = cost;
			}
		}
	}
	return w[l][r];
}
int main() {
	int T, tc;
	for (scanf("%d", &T), tc = 1; tc <= T; ++tc) {
		int i,j, E, W; scanf("%d%d", &E, &W);
		memset(cap, 0, sizeof(cap));
		memset(w, -1, sizeof(w));
		
		for (i = 1; i <= E; ++i) {
			for (j = 1; j <= W; ++j) scanf("%d", X[i] + j),com[j][i][i]=X[i][j];
			
		}
		for (i = 1; i <= W; ++i) {
			for (int l = 1; l <= E; ++l) {
				for (int r = 1+l; r <= E; ++r) {
					com[i][l][r] = min(com[i][l][r - 1], com[i][r][r]);
					cap[l][r] += com[i][l][r];
				}
				cap[l][l] += com[i][l][l];
			}
		}


		printf("Case #%d: %d\n", tc, work(1,E)+cap[1][E]*2);

	}

	return 0;
}
