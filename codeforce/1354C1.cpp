//math, geometry
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
const double PI = acos(-1);
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int T;
	for (scanf("%d", &T); T--;) {
		int n; scanf("%d",&n);
		if (n == 2) printf("%lf\n",1.);
		else {
			double base = PI / n;
			double ans = 1.;
			double theta = base;
			
			int half = n >> 1;
			for (int i = 1; i < half; ++i,theta+=base)
				ans += cos(theta)*2;
			printf("%.9f\n",ans);
		}
	}
	
 
	return 0;
}