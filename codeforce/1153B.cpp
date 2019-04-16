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
int a[101], b[101];
int ans[101][101];
int hij[101][101];
int main() {
	int i, j, n, m, h;
	cin >> n >> m >> h;
	for (i = 1; i <= m; ++i) cin >> a[i];
	for (j = 1; j <= n; ++j) cin >> b[j];
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			cin >> hij[i][j];
			if (hij[i][j]) {
				ans[i][j] = min(a[j],b[i]);
				//cout << a[j] << "," << b[i] << endl;
			}
		}
	}
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			cout << ans[i][j]<<" ";
		}cout << "\n";
	}
	return 0;
}
