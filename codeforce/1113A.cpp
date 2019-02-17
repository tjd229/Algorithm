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
int main() {
	int i, n, v;
	cin >> n >> v;
	int ans = 0;
	int need = n - 1;
	int l = 0;
	for (i = 1; i <= n; ++i) {
		if (l < need) ans += i * min(need, v-l), l += min(need, v-l);
		--need;
		--l;
	}
	printf("%d",ans);
	return 0;
}
