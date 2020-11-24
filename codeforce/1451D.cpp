//game
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
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll d; int k; cin >> d >> k;
		ll dd = d * d;
		ll y = d / k * k;
		ll x = 0;
		int mx = 0;
		while (y >= 0) {
			while (y*y + (x + k)*(x + k) <= dd) x += k;
			int step = y / k + x / k;
			//printf("%d,%d,%d\n",y,x,step);
			if (mx < step) mx = step;
			y -= k;
 
		}
		if (mx & 1) cout << "Ashish\n";
		else cout << "Utkarsh\n";
		
 
	}
 
	return 0;
}