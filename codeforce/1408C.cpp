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
int a[100002];
int main() {
	int t; scanf("%d",&t);
	while (t--) {
		int i, n, l; scanf("%d%d",&n,&l);
		for (i = 1; i <= n; ++i) scanf("%d",a+i);
		a[0] = 0, a[n + 1] = l;
		int pos1 = 0, pos2 = n + 1;
		int s1 = 1, s2 = 1;
		double chk1 = 0, chk2 = 0;
		double ans;
		while (pos1+1 < pos2) {//same time...
			double nxt1 = chk1 + (a[pos1 + 1] - a[pos1]) / (double)s1;
			double nxt2 = chk2 + (a[pos2] - a[pos2-1]) / (double)s2;
			double mn = min(nxt1, nxt2);
			/*printf("1:%d,%d,%f\n", pos1, s1, chk1);
			printf("2:%d,%d,%f\n", pos2, s2, chk2);
			printf("mn:%d\n",mn);*/
			if (nxt1 == mn) {
				++pos1;
				chk1 = nxt1;
				++s1;
			}
			if (nxt2 == mn) {
				--pos2;
				chk2 = nxt2;
				++s2;
			}
		}
		//printf("%d,%d\n",pos1,pos2);
		if (pos1 == pos2) ans = chk1;
		else {
			double real_pos1 = a[pos1];
			double real_pos2 = a[pos2];
			if (chk1 < chk2) {
				double diff = chk2 - chk1;
				real_pos1 += diff * s1;
				chk1 += diff;
			}
			else {
				double diff = chk1 - chk2;
				real_pos2 -= diff * s2;
				chk2 += diff;
			}
			double diff = real_pos2 - real_pos1;
			ans = chk1+diff / (s1 + s2);
			
		}
		printf("%.12f\n",ans);
	}
 
	return 0;
}