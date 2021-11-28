//math
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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int p[101];
int a[101];
int s[101];
int rel[101];
vector<int > ans = { 0,5,7,9,3,8,6,4,2,1 };
//vector<int > ans = { 0,3,4,5,1,2};
int n;
int qry1(int x) {
	for (int i = 1; i <= n; ++i) {
		if (p[i]) a[i] = n;
		else a[i] = 1;
	}
	a[x] = 2;
	cout << "? ";
	for (int i = 1; i <= n; ++i) cout << a[i] << " ";
	cout << endl; int k; cin >> k;
	//int k = q();
	return k;
}
int qry2(int piv, int r) {
	for (int i = 1; i <= n; ++i) {
		if (p[i] == 0) a[i] = piv;
		else if (p[i] == piv) a[i] = r;
		else if (p[i] < piv) a[i] = 1;
		else a[i] = n;
	}
	cout << "? ";
	for (int i = 1; i <= n; ++i) cout << a[i] << " ";
	cout << endl; int k; cin >> k;
	//int k = q();
	return k;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n; 
	int i, r = n;
	int cur = 0;
	for (i = 1; i <= n; ++i) {
		int k = qry1(i);
		if (k == 0) {
			p[i] = r--;
			cur = i;
		}
		else {
			rel[k] = i;
		}
	}
	while (r > 0) {
		if (cur != rel[cur] && rel[cur] > 0) {
			int nxt = rel[cur];
			p[nxt] = r--;
			cur = nxt;
		}
		else {
			int k = qry2(p[cur], r);
			p[k] = r--;
			cur = k;
		}
	}
 
 
	cout << "! ";
	for (int i = 1; i <= n; ++i) cout << p[i] << " ";
	cout << endl;
 
	return 0;
}