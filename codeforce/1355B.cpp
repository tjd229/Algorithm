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
int e[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, i; cin >> N;
		int r = 0;
		for (i = 1; i <= N; ++i) cin >> e[i];
		sort(e + 1, e + 1 + N);
		int g = 0;
		for (i = 1; i <= N; ++i) {
			if (1 + r >= e[i]) {
				r -= e[i] - 1;
				++g;
			}
			else ++r;
		}
		cout << g << "\n";
	}
 
	return 0;
}