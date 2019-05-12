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
int f[10];
int main() {
	int n; string a;
	cin >> n >> a;
	int i;
	for (i = 1; i < 10; ++i) cin >> f[i];
	bool start = 0;
	for (i = 0; i < a.size(); ++i) {
		int d = a[i] - '0';
		if (d < f[d]) {
			a[i] = f[d] + '0';
			start = 1;
		}
		else if (d == f[d]);
		else if (start) break;
	}
	cout << a;
	return 0;
}