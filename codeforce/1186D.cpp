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
double a[100000];
ll ad[100000];
bool op[100000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	ll s = 0;
	double bnd = 1e-6;
	ll p = 0, ne = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		ad[i] = a[i];
		double diff = a[i] - ad[i];
		if (diff < 0) diff = -diff;
		if (bnd<diff) {
			if (a[i] < 0) ++ne;
			else ++p;
			op[i] = 1;
		}
		s += ad[i];
	}
	if (s > 0) p = 0;//to dec
	else if (s < 0) ne = 0;
	else  p = ne = 0;
	
 
	for (int i = 0; i < n; ++i) {
		if (s == 0) p = ne = 0;
		if (p && a[i] > 0 && op[i])// to inc a[i] where a[i]>0
			++ad[i],--p,++s;
		if (ne && a[i] < 0 && op[i])
			--ad[i],--ne,--s;
		cout << ad[i] << "\n";
	}
	return 0;
}