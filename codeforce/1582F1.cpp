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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[100001];
int val[513];
int upd[513];
int ans[513];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		int i, n; cin >> n;
		//set<int> st; st.insert(0);
		for (i = 0; i <= 512; ++i) val[i] = upd[i] = 1e9;
		val[0] = 0; ans[0] = 1;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			for (int j = 0; j <= 512; ++j) {
				//printf("%d,%d,%d\n",j,val[j],a[i]);
				//break;
				if (val[j] < a[i]) {
					int nxt = j ^ a[i];
					upd[nxt] = min(upd[nxt], a[i]);
					//st.insert(nxt);
					ans[nxt] = 1;
				}
			}
			for (int j = 0; j <= 512; ++j) {
				val[j] = min(val[j], upd[j]);
				upd[j] = 1e9;
			}
		}
		int k = 0;
		for (int i = 0; i <= 512; ++i) k += ans[i];
		cout << k << "\n";
		for (int i = 0; i <= 512; ++i) {
			if (ans[i]) cout << i << " ";
		}
		cout << "\n";
	}
 
 
	return 0;
}