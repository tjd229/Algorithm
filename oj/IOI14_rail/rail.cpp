//bs
#include <stdio.h>
#include "rail.h"
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int d[5000][5000];
int call;
int getDist(int i,int j) {
	if (i == j) return 0;
	if (!d[i][j])
		d[i][j] = d[j][i] = getDistance(i, j), ++call;
	return d[i][j];
}
void findLocation(int N, int first, int location[], int stype[])
{
	int i; location[0] = first; stype[0] = 1;	
	vector<pii > v; int rc=0;
	int fi = 0; int mn = 1e9;
	for (i = 1; i < N; ++i) {
		int d = getDist(0, i);
		if (mn > d) {
			mn = d; 
			fi = i;
		}
	}
	location[fi] = first + mn;
	stype[fi] = 2;
	for (i = 1; i < N; ++i) {//find closest C
		if (i == fi) continue;
		int dist = getDist(fi,i);
		if (getDist(0, i) > dist && dist < getDist(0, fi)
			&& getDist(0, i) - getDist(0, fi) == dist) {			
			stype[i] = 1;
			location[i] = location[fi] - dist;
			if (location[rc] < location[i]) rc = i;			
		}
		else v.push_back({getDist(i,0),i});
		
	}
	sort(v.begin(), v.end());
	vector<pii > left = { {-location[rc],rc} };
	vector<pii >right = { {location[fi],fi} }; //coord,ix
	for (auto p : v) {
		int last = call;
		int x = p.second;
		d[rc][x] = d[x][rc] = getDist(0, x) - (location[rc]-location[0]);
		//printf("x:%d,%d\n", x,d[rc][x]);
		if (getDist(rc, x) < getDist(x, fi)) {
			int r = right.back().second;
			int pred = location[r]-getDist(r,x);
			if (pred > first) {
				pii p = {pred,10000};
				auto lb = upper_bound(right.begin(),right.end(),p);
				int nr = lb->second;
				d[nr][x] = d[x][nr] = getDist(r,x)-(location[r]-location[nr]);

				r = nr;
			}
			//init case && inner condi.
			if (r !=fi && getDist(rc, x) == getDist(x, r) + getDist(rc, r)) {
				stype[x] = 1;
				location[x] = pred;
			}
			else {
				stype[x] = 2;
				location[x] = location[rc]+getDist(rc,x);
				right.push_back({location[x],x});
			}
		}
		else {
			int l = left.back().second;
			int pred = location[l] + getDist(l,x);
			if (pred < first) {
				pii p = {-pred,10000};
				auto lb = upper_bound(left.begin(), left.end(), p);
				int nl = lb->second;
				d[nl][x] = d[x][nl] = getDist(l, x) - (location[nl] - location[l]);
				l = nl;
			}
			if (l !=rc&& getDist(fi, x) == getDist(l, x) + getDist(fi, l)) {
				stype[x] = 2;
				location[x] = pred;
			}
			else {
				stype[x] = 1;
				location[x] = location[fi] - getDist(fi,x);
				left.push_back({-location[x],x});
			}
		}
	}
}
