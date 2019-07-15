//game
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		
			int s = n;
			if (k % 3) {
				int pos = s;
				if (pos % 3 == 0) cout << "Bob\n";
				else cout << "Alice\n";
			}
			else {
				int d = k / 3;
				int r = d * 3 + 1;
				int pos = s % r;
				if (pos < r - 1 && pos % 3 == 0)
					cout << "Bob\n";
				else cout << "Alice\n";
			}
		
	}
	return 0;
}