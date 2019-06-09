//math
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
	int x, y, z; cin >> x >> y >> z;
	int up = x + z;
	int d = y + z;
	int flag1 = 0, flag2 = 0;
	if (z == 0) {
		if (x > y) printf("+");
		else if (x < y) printf("-");
		else printf("0");
	}
	else {
		if (up < y) flag2 = 1;
		if (d < x) flag1 = 1;
		if (flag1 && flag2 == 0) printf("+");
		else if (flag1 == 0 && flag2) printf("-");
		else printf("?");
	}
	return 0;
}