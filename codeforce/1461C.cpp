//math, greedy
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
int c[100002];
int a[100001];
int r[100001];
double p[100001];
int main() {
	
	int t; scanf("%d",&t);
	while (t--) {
		int i, n, m; scanf("%d%d",&n,&m);
		for (i = 1; i <= n; ++i) c[i] = 0;
		for (i = 1; i <= n; ++i) scanf("%d",a+i);
		c[n + 1] = 1;
		for (i = n; i > 0; --i) {
			if (a[i] == i) c[i] = 1;
			else break;
		}
		double ans = 0;
		double acc = 1;
		for(i=0;i<m;++i) scanf("%d%lf", r+i, p+i);
		if (c[1] == 1) {
			printf("1.000000\n");
			continue;
		}
		for (i = 0; i < m; ++i) {
			//scanf("%d%lf",r+i,p+i);
			//printf("%d %f\n",r[i],p[i]);
			if (c[r[i] + 1]) {
				if (p[i] == 1) {
					ans = 1.0;
					break;
				}
				ans += acc * p[i];
				acc *= (1.- p[i]);
			}
		}
		printf("%lf\n",ans);
 
	}
 
	return 0;
}