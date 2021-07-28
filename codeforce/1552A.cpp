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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n;
		int k = 0;
		string s; cin >> n >> s;
		vector<int> origin;
		for (auto c : s)
			origin.push_back(c-'a');
		vector<int> sorted = origin;
		sort(sorted.begin(), sorted.end());
		for (i = 0; i < n; ++i)
			k+=sorted[i] != origin[i];
		cout << k << "\n";
	}
 
	return 0;
}