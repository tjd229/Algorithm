//game
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
int dig[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n; scanf("%d",&n);
		int ans = 0;
		for (i = 1; i <= n; ++i) scanf("%1d",dig+i);
		if (n == 1) {
			ans = dig[1] & 1;
			if (ans == 0) ans = 2;
		}
		else if (n & 1) {
			for (i = 1; i <= n&&ans==0; i += 2) {
				if (dig[i] & 1) ans = 1;
			}
			if (ans == 0) ans = 2;
		}
		else {
			for (i = 2; i <= n && ans == 0; i += 2) {
				if ((dig[i] & 1) == 0) ans = 2;
			}
			if (ans == 0) ans = 1;
		}
		printf("%d\n",ans);
	}
 
	return 0;
}