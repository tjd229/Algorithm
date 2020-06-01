//math, geometry

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
ll s[500001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int A, B, C, D;
	ll ans = 0;
	cin >> A >> B >> C >> D;
	
	int i,len = B - A+1;
	for (s[1] = 1, i = 2; i <= len; ++i) {
		s[i] = s[i - 1] + i;
	}
	int piv = A + B-1;
	ll pie = C-B+ 1;
	int r= 0;
	int st=len-1, ed=len-1;
	int z = min(C, piv);
	//printf("%lld,%lld\n",pie,len);
	for (; z <= D; ++z) {
		if (z > piv) {
			if (st > 0)
				--st;
			--pie;
		}
		if (pie < 0) {
			pie = 0;
			--ed;
		}
 
		if (z>=C ) {
			ans += pie * len;
			//side
			if (st <= ed) ans += s[ed] - s[st];
		}
		
		//printf("%d:",z);
		//cout << ans << endl;
		
	}
	cout << ans;
 
	return 0;
}