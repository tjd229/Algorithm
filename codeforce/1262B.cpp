//greedy
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
int q[100001],p[100001];
int use[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		priority_queue<int> pq;
		int stamp = t + 1;
		for (i = 1; i <= n; ++i) {
			cin >> q[i];
			pq.push(-i);
			p[i] = 0;
		}
		
		for (i = 1; i <= n; ++i) {
			if (use[q[i]] != stamp) {
				p[i] = q[i];
				use[q[i]] = stamp;//mono
			}
		}
		int last = 0;
		bool flag = 1;
		for (i = 1; i <= n && flag; ++i) {
			if (p[i]) {
				last = p[i];
				continue;
			}
			while (use[-pq.top()] == stamp) 
				pq.pop();
			int x = -pq.top();
			pq.pop();
			if (last < x) flag = 0;
			p[i] = x;			
			
		}
		if (flag) {
			for (int i = 1; i <= n; ++i) cout << p[i] << " ";			
		}
		else cout << -1;
		cout << "\n";
	}
 
	return 0;
}