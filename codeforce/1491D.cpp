//greedy, math
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
int pop_cnt(int x) {
	int cnt = 0;
	while (x) {
		++cnt;
		x -= (x & -x);
	}
	return cnt;
}
void decomp(int x, int *b) {
	int p = 0;
	while (x) {
		b[p] = x & 1;
		x >>= 1; ++p;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		if (u > v) {
			cout << "NO\n";
			continue;
		}
		else if (u == v) {
			cout << "YES\n";
			continue;
 
		}
		int u1 = pop_cnt(u), v1 = pop_cnt(v);
		if (u1 < v1) {
			cout << "NO\n";
			continue;
		}
		int bu[35] = { 0 }; decomp(u, bu);
		int bv[35] = { 0 }; decomp(v, bv);
		
		int top = 33;
		while (bv[top] == 0) --top;
		bool flag = 1;
		int last = -1;
		for (int i = top; i >= 0; --i) {
			if (bu[i]) {
				if (top >= 0) {
					if (top > i) {
						last = top--;
						while (top>=0 && bv[top] == 0)--top;
					}
					else if (top == i) {						
						//last = -1; 
						--top;
						while (top >= 0 && bv[top] == 0)--top;
					}
					else {//top<i
						//last chk
						if (last == -1) flag = 0;
					}
				}
				else {
					if (last == -1) flag = 0;
				}
			}
		}
		//printf("%d\n",top);
		if (top >= 0) flag = 0;
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}