//string
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
char c[3] = {'a','b','c'};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, k; cin >> n >> k;
		
		for (i = 1; i <= n; ++i) {
			cout << c[i % 3];
		}
		cout << "\n";
	}
 
	return 0;
}