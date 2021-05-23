//https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c
//implementation
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
int rev(int i,int j) {
	int cost = j - i + 1;
	while (i < j) {
		L[i] ^= L[j] ^= L[i] ^= L[j];
		++i; --j;
	}
	return cost;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc, T; cin >> T;
	for (tc = 1; tc <= T; ++tc) {
		int i, N; cin >> N;
		for (i = 1; i <= N; ++i) cin >> L[i];
		int cost = 0;
		for (i = 1; i < N; ++i) {
			int mn = L[i];
			int j = i ;
			for (int k = j; k <= N; ++k) {
				if (mn > L[k]) {
					mn = L[k];
					j = k;
				}
			}
			cost += rev(i, j);
		}
		cout << "Case #" << tc << ": " << cost << "\n";
	}

	return 0;
}