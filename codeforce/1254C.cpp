//geometry, ccw

#include <stdio.h>
#include <vector>
#include <deque>
#include <algorithm>
#define ll long long
#define pli pair<ll,int>
using namespace std;
ll qry(int t, int i, int j, int k) {
	printf("%d %d %d %d\n", t, i, j, k); fflush(stdout);
	ll res; scanf("%I64d",&res);
	return res;
}
void ordering(vector<int> &v1,vector<pli > &v2) {
	if (v1.empty()) return;
	for (auto x : v1) 
		v2.push_back({qry(1,1,2,x),x});
	sort(v2.begin(), v2.end());
}
int main() {
	int i, n; scanf("%d",&n);
	vector<int> up,down;
	vector<pli > vu, vd;
	deque<int> du, dd;
	for (i = 3; i <= n; ++i) {
		if (qry(2, 1, 2, i) > 0) up.push_back(i);
		else down.push_back(i);
	}
	ordering(up, vu); ordering(down, vd);
	if (vu.size()) {
		int top = vu.back().second; vu.pop_back();
		du.push_back(top); 
		while (vu.size()) {
			int x= vu.back().second; vu.pop_back();
			if (qry(2, 1, top, x) > 0) du.push_front(x);
			else du.push_back(x);
		}
	}
	if (vd.size()) {
		int top = vd.back().second; vd.pop_back();
		dd.push_back(top);
		while (vd.size()) {
			int x = vd.back().second; vd.pop_back();
			if (qry(2, 1, top, x) < 0) dd.push_front(x);
			else dd.push_back(x);
		}
	}
	printf("0 1 ");
	while (dd.size()) {
		printf("%d ",dd.front());
		dd.pop_front();
	}
	printf("2 ");
	while (du.size()) {
		printf("%d ",du.back());
		du.pop_back();
	}
	fflush(stdout);
	return 0;
}
