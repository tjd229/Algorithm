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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s; cin >> n >> s;
	int l = 0, r = 0;
	for (auto c : s) {
		if (c == 'L') --l;
		else ++r;
	}
	cout << r - l + 1;
 
	return 0;
}