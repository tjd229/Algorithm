//greedy
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
int src[21][20];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i,j, n; string A, B;
		cin >> n >> A >> B;
		if (A == B) {
			cout << "0\n";
			continue;
		}
		bool flag = 1;
		for (i = 0; i < n && flag; ++i) {
			if (A[i] > B[i]) flag = 0;
		}
		if (!flag) {
			cout << "-1\n";
			continue;
		}
		for (i = 0; i < 20; ++i)for ( j = 0; j < 20; ++j) src[i][j] = 0;
		for (i = 0; i < n; ++i) {
			if (A[i] < B[i]) {
				int u = A[i] - 'a';
				int v = B[i] - 'a';
				src[u][v] = 1;
			}
		}
		int ans = 0;
		for (i = 0; i < 20; ++i) {
			int tgt = i;
			for ( j = i+1; j < 20; ++j) {
				if (src[i][j]) {
					++ans;
					tgt = j;
					break;
				}
			}
			for (++j; j < 20; ++j) src[tgt][j] |= src[i][j];
		}
		cout << ans << "\n";
	}
 
	return 0;
}