//greedy
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
int a[1000];
int main() {
	int i, n, h;
	int ans = 0;
	cin >> n >> h;
	for (i = 0; i < n; ++i) cin >> a[i];
	for (i = 0; i < n; ++i) {
		sort(a, a + i + 1);
		reverse(a, a + i + 1);
		int s = 0;
		for (int j = 0; j <= i; j += 2) {
			//if (j + 1 <= i) s += a[j+1];
			/*else */
			s += a[j];
		}
		//cout << s << endl;
		if (h < s) break;
		++ans;
	}
	cout << ans;
	return 0;
}
