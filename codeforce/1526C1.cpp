//dp
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
ll d[2001];
ll t[2001];
int a[2001];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n; cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	int mx = 0;
	for (i = 1; i <= n; ++i) {
		for (int j = 0; j <= mx + 1; ++j) t[j] = -1;
		for (int j = 0; j <= mx; ++j) {
			if (d[j] + a[i] < 0) t[j + 1] = -1;
			else {
				t[j + 1] = d[j] + a[i];
				//mx = max(mx, j + 1);
			}
		}
		if (t[mx + 1] != -1) ++mx;
		for (int j = 1; j <= mx; ++j) {
			if (d[j] < t[j]) d[j] = t[j];
		}
	}
	cout << mx;
 
	return 0;
}