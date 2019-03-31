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
int door[200001];
int main() {
	int i, n;
	int l, r;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> door[i];
		if (door[i]) l = i;
		else r = i;
	}
	cout << min(l, r);
	
	return 0;
}
