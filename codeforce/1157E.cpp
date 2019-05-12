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
multiset<int> st;
int a[200001];
int main() {
	int i, n; cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	for (i = 1; i <= n; ++i) {
		int b; cin >> b;
		st.insert(b);
	}
	for (i = 1; i < n; ++i) {
		auto it = st.lower_bound(n-a[i]);
		if (it == st.end()) it = st.lower_bound(0);
		cout << (a[i] + *it) % n<<" ";
		st.erase(it);
	}
	auto it = st.lower_bound(0);
	cout << (a[n] + *it) % n << " ";

	return 0;
}