//greedy
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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int g[11111];
int ask(int a, int b, int c) {
	cout << "? " << a << " " << b << " " << c << endl;
	int r; cin >> r;
	return r;
}
int main() {
	int t; cin >> t;
	while (t--) {
		vector<int> v;
		int i, n; cin >> n;
		int g0;
		int g1;
		int im, crew;
		for (i = 1; i <= n; i += 3) {
			g[i] = ask(i, i + 1, i + 2);
			if (g[i] == 0) g0 = i;
			else g1 = i;
		}
		int a = g0, b = g0 + 1;
		int r1 = ask(a, b, g1), r2 = ask(a, b, g1 + 1);
		if (r1 ==0 && 0== r2) {
			v.push_back(a);
			v.push_back(b);
			im = a;
 
			int r = ask(im, g1, g1 + 1);
			if (r == 0) crew = g1 + 2;
			else crew = g1;//opt able
 
			r = ask(im, crew, g0+2);
			if (r == 0) v.push_back(g0 + 2);//chk 3rd g0's member
 
			for (i = 0; i < 3; ++i) {//pick one g1's im or zero
				if (crew == g1 + i) continue;
				r = ask(im, crew, g1 + i);
				if (r == 0) {
					v.push_back(g1+i);
					break; //maximum im is 1
				}
			}
		}
		else {
			im = g0 + 2;
			v.push_back(im);
			if (r1 == 1 && r2 == 1) {
				crew = g1;
			}
			else if (r1 == 0) {//r2==1
				crew = g1 + 1;
			}
			else {//r2==0
				crew = g1;
			}
			int r = ask(im, crew, g0);
			if (r == 0) v.push_back(g0);
			else v.push_back(g0 + 1);
 
			for (i = 0; i < 3; ++i) {//pick one g1's im or zero
				if (crew == g1 + i) continue;
				r = ask(im, crew, g1 + i);
				if (r == 0) {
					v.push_back(g1 + i);
					break; //maximum im is 1
				}
			}
		}
 
		for (i = 1; i <= n; i += 3) {
			if (i == g0 || i == g1) continue;
			if (ask(im, crew, i) == 0) v.push_back(i);
			if (ask(im, crew, i+1) == 0) v.push_back(i+1);
			if (ask(im, crew, i+2) == 0) v.push_back(i+2);
		}
		cout<<"! " << v.size() << " ";
		for (auto x : v) cout << x << " ";
		cout << endl;
		
	}
 
 
	return 0;
}