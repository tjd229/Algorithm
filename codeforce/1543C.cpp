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
float c, m, p;
float v;
double ans;
int stk = 0;
void sim(int x, double c, double m, double p,double cum_p) {
	ans += x * p*cum_p;
	++stk;
	//printf("%f %f %f\n",c,m,p);
	//printf("%d,%f\n",x, p*cum_p);
	if (c > 0) {
		double _c=c, _m=m, _p=p;
		double d;
		double prob = cum_p * c;
		if (c > v) {
			d = v;
			_c = c - v;			
		}
		else {
			d = c;
			_c = 0;
		}
		if (_m > 0) {
			_m += d / 2;
			_p += d / 2;
		}
		else _p += d;
		//printf("c\n");
		sim(x + 1, _c, _m, _p, prob);
	}
	if (m > 0) {
		double _c = c, _m = m, _p = p;
		double d;
		double prob = cum_p * m;
		if (m > v) {
			d = v;
			_m = m - v;
		}
		else {
			d = m;
			_m = 0;
		}
		if (_c > 0) {
			_c += d / 2;
			_p += d / 2;
		}
		else _p += d;
		//printf("m\n");
		sim(x + 1, _c, _m, _p,prob);
	}
}
int main() {
	
	int t; scanf("%d",&t);
	while (t--) {
		ans = 0;
		//cin >> c >> m >> p >> v;
		scanf("%f%f%f%f",&c,&m,&p,&v);
		sim(1, c, m, p,1);
		printf("%.7f\n",ans);
	}
 
	return 0;
}