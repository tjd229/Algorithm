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
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[10001];
//vector<int> _a = { 0,1,6,4,2,3,5,4 };
//int ask(int q, int i, int j) {
//	if (q == 1) return _a[i] | _a[j];
//	else return _a[i] & _a[j];
//}
int ask(int q, int i, int j) {
	if (q == 1) cout << "or ";
	else cout << "and ";
	cout << i << " " << j << endl;
	int res;  cin >> res;
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; t = 1;
	while (t--) {
		int i, n,k; cin >> n>>k;
		int ab = ask(1, 1, 2) + ask(2, 1, 2);
		int bc = ask(1, 2, 3) + ask(2, 2, 3);
		int ac = ask(1, 1, 3) + ask(2, 1, 3);
		int aa = ab - bc + ac; 
		a[1] = aa >> 1; a[2] = ab - a[1]; a[3] = ac - a[1];
		for (i = 4; i <= n; ++i) 
			a[i] = ask(1, i - 1, i) + ask(2, i - 1, i) - a[i-1];
		//for (i = 1; i <= n; ++i)
			//cout << a[i] << " ";
		sort(a + 1, a + 1 + n);
		cout << "finish " << a[k] << endl;
		
	}
 
	return 0;
}