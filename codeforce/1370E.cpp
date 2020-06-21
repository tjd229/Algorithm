//math, greedy
#include <stdio.h>
#include <queue>
using namespace std;
int s[1000001], t[1000001];
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%1d",s+i);
	for (i = 1; i <= n; ++i) scanf("%1d",t+i);
	int sum = 0;
	deque<int> dq;
	for (i = 1; i <= n; ++i) {
		if (s[i] != t[i]) {
			int x = s[i] ? 1 : -1;
			dq.push_back(x);
			sum += x;
		}
	}
	if (dq.empty())
		printf("0");
	else if (sum)
		printf("-1");
	else {
		while (dq.front() == dq.back()) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
		int val = 0;
		int mx = 0, mn = 0;
		while (dq.size()) {			
			val += dq.front(); dq.pop_front();
			if (mx < val) mx = val;
			if (mn > val) mn = val;			
		}
		if (mx < val) mx = val;
		if (mn > val) mn = val;		
		
		printf("%d",mx-mn);
	}
	return 0;
 
}