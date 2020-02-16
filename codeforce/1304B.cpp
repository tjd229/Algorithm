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
int mat[101][101];
int n, m;
int use[101];
string str[101];
bool paring(int a,int b) {
	int l = 0, r = m - 1;
	for (; l < m; ++l, --r) {
		if (str[a][l] != str[b][r]) return 0;
	}
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	deque<int> l, r;
	int i; cin >> n >> m;
	for (i = 1; i <= n; ++i) {
		cin >> str[i];
	}
	for (i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			mat[i][j] = mat[j][i] = paring(i,j);
		}
	}
	for (i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (mat[i][j] && use[i] == 0 && use[j] == 0) {
				use[i] = use[j] = 1;
				l.push_back(i);
				r.push_front(j);
				break;
			}
		}
	}
	for (i = 1; i <= n; ++i) {
		if (mat[i][i] && use[i] == 0) {
			use[i] = 1;
			l.push_back(i);
			break;
		}
	}
	int len = l.size() + r.size();
	len *= m;
	cout << len << "\n";
	while (l.size()) {
		int x =  l.front();
		cout << str[x];
		l.pop_front();
	}
	while (r.size()) {
		int x = r.front();
		cout << str[x];
		r.pop_front();
	}
	return 0;
}