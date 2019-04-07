//greedy

 #include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int A[500][500], B[500][500];
int C[500][500];
int main() {
	int i, j, n, m;
	cin >> n >> m;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) cin >> A[i][j];
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) cin >> B[i][j];
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			C[i][j] = (A[i][j] != B[i][j]);
		}
	}
	int s = 0;
	for (i = 0; i < n - 1; ++i) {
		for (j = 0; j < m - 1; ++j) {
			if (C[i][j]) {
				C[i][j] = 0;
				C[i][j + 1] ^= 1;
				C[i+1][j + 1] ^= 1;
				C[i+1][j] ^= 1;
			}
		}
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			s += C[i][j];
		}
	}
	cout << (s ? "No" : "Yes");
	return 0;
}
