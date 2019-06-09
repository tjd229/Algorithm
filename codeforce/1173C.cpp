//implementation
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
int a[200001], b[200001];
int nxt[200001];
int n;
int sim() {
	int i;
	int in[200001] = { 0 };
	for (i = 1; i <= n; ++i) {
		if (b[i] == 1) break;
	}
	int p = 1;
	if (i <= n) {
		for (; i <= n; ++i) {
			if (b[i] != p) {
				p = 1;
				break;
			}
			++p;
		}
	}
	for (i = 1; i <= n; ++i) in[a[i]] = 1;
	int t = 1;
	while (p <= n) {
		if (in[p] == 0) return -1;
		in[b[t]] = 1;
		++p; ++t;
	}
	return t - 1;
}
int main() {
	int i; cin >> n;

	for (i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (i = 1; i <= n; ++i) {
		cin >> b[i];
		if (b[i]) nxt[b[i]] = i;
	}
	//perfect case
	for (i = 1; i <= n; ++i) {
		if (b[i] != i) break;
	}
	if (i == n && b[n] == n) {
		printf("0"); return 0;
	}
	//tail case //sim
	int s = sim();
	if (s >= 0) {
		cout << s; return 0;
	}
	//1 is in case chk
	int mn = 1e9;
	for (i = 1; i <= n; ++i) {
		if (b[i] && mn > b[i]) mn = b[i];
	}
	if (mn > n) mn = 1;
	int t = nxt[mn] - mn;
	for (i = mn; i <= n; ++i) {
		if (nxt[i] >= i) {
			int d = nxt[i] - i;
			if (t < d) t = d;
		}
	}
	
	cout << n + t + 1;


	return 0;
}