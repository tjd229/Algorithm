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
int a[101],b[101];
int main() {
	int i, n;
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	sort(a+1, a +1+ n);
	int l = 1;
	int r = n;
	i = n;
	while (l <= r) {
		b[l++] = a[i--];
		if (i ==0) break;
		b[r--] = a[i--];
	}
	for (i = 1; i <= n; ++i) {
		cout << b[i] << " ";
	}
	return 0;
}
