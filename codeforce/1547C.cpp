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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		vector<int> A, B,C;
		int i, k, n, m;
		cin >> k >> n >> m;
		for (i = 0; i < n; ++i) {
			int a; cin >> a;
			A.push_back(a);
		}
		for (i = 0; i < m; ++i) {
			int b; cin >> b;
			B.push_back(b);
		}
		reverse(A.begin(), A.end()); reverse(B.begin(), B.end());
		while (A.size() || B.size()) {
			if (A.empty()) {
				C.push_back(B.back());
				B.pop_back();
			}
			else if (B.empty()) {
				C.push_back(A.back());
				A.pop_back();
			}
			else {
				if (B.back() < A.back()) {
					C.push_back(B.back());
					B.pop_back();
 
				}
				else {
					C.push_back(A.back());
					A.pop_back();
				}
			}
		}
		bool flag = 1;
		for (i = 0; i < C.size() && flag; ++i) {
			if (C[i] == 0) ++k;
			else {
				if (C[i] > k) flag = 0;
			}
		}
		if (flag) {
			for (auto x : C) cout << x << " ";
			cout << "\n";
		}
		else cout << "-1\n";
	}
 
	return 0;
}