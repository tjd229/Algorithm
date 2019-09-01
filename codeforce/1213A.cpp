//implementation
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
int x[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int cost[2] = { 0 };
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
		++cost[x[i] & 1];
	}
	cout << min(cost[0], cost[1]);
 
	return 0;
}