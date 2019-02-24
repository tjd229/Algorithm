//geometry
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
	int w1, w2, h1, h2;
	ll ans = 0;
	cin >> w1 >> h1 >> w2 >> h2;
	ans += w1 + w2 + 2 + 2;
	ans += h1 + h2 + h1 + h2;
	ans += w1-w2;
	cout << ans;
	return 0;
}
