//https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145
//dp
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int d[1000][4];
//JJ JC CJ CC
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc, T; cin >> T;
	for (tc = 1; tc <= T; ++tc) {
		int i, X, Y; string S; cin >> X >> Y >> S;
		int N = S.size();
		for (i = 0; i < N; ++i) {
			for (int j = 0; j < 4; ++j) d[i][j] = 1e9;
		}
		for (int j = 0; j < 4; ++j) d[0][j] = 0;
		for (i = 1; i < N; ++i) {
			
			if (S[i - 1] != 'C' && S[i] != 'C')
				d[i][0] = min(d[i - 1][0], d[i - 1][2]);
			if (S[i - 1] != 'C' && S[i] != 'J')
				d[i][1] = min(d[i - 1][0], d[i - 1][2]) + Y;
			if (S[i - 1] != 'J' && S[i] != 'C')
				d[i][2] = min(d[i - 1][1], d[i - 1][3]) + X;
			if (S[i - 1] != 'J' && S[i] != 'J')
				d[i][3] = min(d[i - 1][1], d[i - 1][3]);
			
			if (S[i] == 'J') d[i][1] = d[i][3] = 1e9;
			if (S[i] == 'C') d[i][0] = d[i][2] = 1e9;
		}

		int ans = d[N-1][0];
		for (i = 1; i < 4; ++i) ans = min(ans, d[N-1][i]);
		
		cout << "Case #" << tc << ": "<<ans<<"\n";
		
		
	}

	return 0;
}