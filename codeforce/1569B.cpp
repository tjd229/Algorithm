//greedy, graph
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
char mat[51][51];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; string s; cin >> n >> s;
		int num[2] = { 0 };
		vector<int> r;
		for (auto ex : s) {
			if (ex == '1') ++num[0];
			else {
				++num[1];
			}
		}
		if (num[1] == 1 || num[1] == 2)
			cout << "NO\n";
		else {
			for (i = 0; i < n; ++i) {
				if (s[i] == '2') r.push_back(i);
			}
			for (i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (i == j) mat[i][j] = 'X';
					else mat[i][j] = '=';
				}
			}
			for (i = 1; i < r.size(); ++i) {
				int a = r[i - 1], b = r[i];
				mat[a][b] = '+'; mat[b][a] = '-';
				
			}
			if (r.size()) {
				int a = r.back(), b = r[0];
				mat[a][b] = '+'; mat[b][a] = '-';
			}
			cout << "YES\n";
			for (i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					cout << mat[i][j];
				}
				cout << "\n";
			}
			
		}
	}
	
 
	return 0;
}