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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, t;
	cin >> t;
	while (t--) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int x = a / c + ((a%c) > 0);
		int y = b / d + ((b%d) > 0);
		if (x + y <= k)
			cout << x << " " << y << "\n";
		else cout<<"-1\n";
	}
	
 
	return 0;
}