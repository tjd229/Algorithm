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
int a[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int s = 0;
	vector<int> v = { 1 };
	for (int i = 1; i <= n; ++i) cin >> a[i],s+=a[i];
	int c = a[1];
	for (int i = 2; i <= n; ++i) {
		if (a[1] >= a[i] + a[i]) {
			v.push_back(i);
			c += a[i];
		}
	}
	if (c + c <= s) cout << 0;
	else {
		cout << v.size() << "\n";
		for (auto p : v) cout << p << " ";
	}
	return 0;
}