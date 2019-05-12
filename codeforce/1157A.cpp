//math
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
	int n; cin >> n;
	set<int> st;
	st.insert(n);
	int _n = n;
	while (1) {
		++n;
		//if (++cnt > _n) break;
		while (n % 10 == 0) n /= 10;
		//cout << n << endl;
		if (st.find(n) != st.end()) break;
		st.insert(n);
	}
	
	cout << st.size();
	return 0;
}