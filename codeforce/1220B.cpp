//math
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[1001];
int M[1003][1003];
//int M[8][8];
int gcd(int a, int b) {//a<b
	if (a > b) a ^= b ^= a ^= b;
	if (a == 0) return b;
	return gcd(b%a,a);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j, n; cin >> n;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) cin >> M[i][j];
		M[i][n + 1] = M[i][1];
		M[i][n + 2] = M[i][2];
	}
	for (j = 1; j <= n + 2; ++j) {
		M[n + 1][j] = M[1][j];
		M[n + 2][j] = M[2][j];
	}
	for (i = 1; i <= n; ++i) {
		ll sq = ((ll)M[i][i + 1] * M[i][i + 2]) / M[i + 1][i + 2];
		a[i] = round(sqrt(sq));
		cout << a[i] << " ";
	}
	
	return 0;
}