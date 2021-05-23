//https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d12d7
//math

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
int L[101];
const int dx[2] = {1,-1};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc, T; cin >> T;
	for (tc = 1; tc <= T; ++tc) {
		int i, N,C; cin >> N>>C;
		cout << "Case #" << tc << ": ";
		int base = N - 1;
		int mx = base;
		for (i = base; i > 0; --i) mx += i;
		if (C<base || C>mx)
			cout << "IMPOSSIBLE\n";
		
		else {
			C -= base;
			int l = 1, r = N;
			int x = l;
			int d = 0;
			int perm = 1;
			while (perm<=N) {
				if (C==0 || C < base) {
					L[x] = perm++;
					x += dx[d];
				}
				else {//C>=base
					C -= base;
					if (d == 0) {
						l = x; x = r;
						d = 1;
					}
					else {
						r = x; x = l;
						d = 0;
					}
					L[x] = perm++;
					x += dx[d];
				}
				--base;
			}
			for (i = 1; i <= N; ++i)
				cout << L[i] << " ";
			cout << "\n";
		}
	}

	return 0;
}