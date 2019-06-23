//implementation
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[100001];
int b[100001];
int A[100001], B[100001];
int main() {
	int i, n, q;
	cin >> n >> q;
	deque<int> dq;
	for (i = 0; i < n; ++i) cin >> a[i],dq.push_back(a[i]);
	for (i = 1; i < n; ++i) {
		A[i] = dq.front(); dq.pop_front();
		B[i] = dq.front(); dq.pop_front();
		if (A[i] > B[i]) {
			dq.push_front(A[i]);
			dq.push_back(B[i]);
		}
		else {
			dq.push_front(B[i]);
			dq.push_back(A[i]);
		}
	}
	int _A;
	for (_A=dq.front(),dq.pop_front(), i = 0; dq.size(); ++i)
		b[i] = dq.front(), dq.pop_front();
	while (q--) {
		ll m; cin >> m;
		if (m < n) {
			cout << A[m] << " " << B[m] << "\n";
		}
		else {
			int ix = (m - n ) % (n - 1);
			cout << _A << " " << b[ix] << "\n";
		}
	}
	return 0;
}