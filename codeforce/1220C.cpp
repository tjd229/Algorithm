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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	char mn = s[0];
	for (auto c : s) {
		if (mn < c) cout << "Ann\n";
		else {
			cout << "Mike\n";
			mn = c;
		}
	}
 
	return 0;
}