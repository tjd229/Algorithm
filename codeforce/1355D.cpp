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
int a[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,N, S; cin >> N >> S;
	int sum = 0;
	for (i = 1; i < N; ++i) a[i] = 1, --S,++sum;
	if (N == 1 && S>1) {
		cout << "YES\n";
		cout << S << "\n" << (S >> 1);
	}
	else if (sum+1>=S) {
		cout << "NO";
	}
	else {
		cout << "YES\n";
		a[N] = S;
		for (i = 1; i <= N; ++i) cout << a[i]<<" ";
		cout << "\n" << 1 + sum;
	}
	
 
	return 0;
}