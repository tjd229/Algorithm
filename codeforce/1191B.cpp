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
int m[10];
int p[10];
int s[10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ix[3]; char c[3];
	for (int i = 0; i < 3; ++i) {
		scanf(" %1d%c", &ix[i], &c[i]);
		if (c[i] == 'm') m[ix[i]]++;
		else if (c[i] == 's') s[ix[i]]++;
		else p[ix[i]]++;
	}
	
	int ans = 3;
	for (int i = 1; i <= 7; ++i) {
		int sum = (m[i]>0) + (m[i + 1]>0) + (m[i + 2]>0);
		ans = min(ans, 3 - sum);
		sum = (s[i]>0) + (s[i + 1]>0) + (s[i + 2]>0);
		ans = min(ans, 3 - sum);
		sum = (p[i]>0) + (p[i + 1]>0) + (p[i + 2]>0);
		ans = min(ans, 3 - sum);
	}
	for (int i = 1; i < 10; ++i) {
		ans = min(ans,3-m[i]);
		ans = min(ans, 3 - p[i]);
 
		ans = min(ans, 3 - s[i]);
	}
	cout << ans;
	return 0;
}