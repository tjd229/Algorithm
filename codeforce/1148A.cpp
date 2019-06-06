//greedy

 #include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int main() {
	int a, b, c; cin >> a >> b >> c;
	ll mn = min(a, b);
	ll ans = mn +mn+ c+c;
	a -= mn; b -= mn;
	if (a > 0) ++ans;
	if (b > 0) ++ans;
	cout << ans;
	
	return 0;
}