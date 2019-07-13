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
	int x; cin >> x;
	int r = x % 4;
	if (r == 1) printf("0 A");
	else if (r == 3) printf("2 A");
	else if (r == 2) printf("1 B");
	else printf("1 A");
	
	return 0;
}