//implementation
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
int main() {
	int n; cin >> n;
	int p = 4; int ans = 1;
	for (int i = 1; i < n; ++i) {
		ans += p;
		p += 4;
	}
	cout << ans;
	return 0;
}