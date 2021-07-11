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
int a[100001];
int vis[200001];
int pos[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	int stamp = 1;
	while (t--) {
		int i, j, n; cin >> n;
		int nn = n + n;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			vis[a[i]] = stamp;
			pos[a[i]] = i;
		}
		int ans = 0;
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= nn; ++j) {
				int mul = a[i] * j;
				
				if (mul > nn) break;
				//printf("%d,%d\n",a[i],j);
				if (vis[j] != stamp) continue;
				int jpos = pos[j];
				//printf("!:%d,%d\n", i,jpos);
				if (i < jpos && i+jpos==mul) ++ans;
			}
		}
		cout << ans << "\n";
		++stamp;
	}
 
 
	return 0;
}