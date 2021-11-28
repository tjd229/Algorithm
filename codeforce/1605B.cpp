//greedy
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int s[1001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%1d",s+i);
		bool flag = 1;
		for (i = 2; i <= n && flag; ++i) {
			if (s[i] < s[i - 1]) flag = 0;
		}
		if (flag) printf("0\n");
		else {
			vector<int> stk;
			int cum = 0;
			for (i = 1; i <= n; ++i) cum += s[i];
			for (i = n; i > n - cum; --i) {
				if (s[i] == 0) stk.push_back(i);
			}
			for (i = n - cum; i > 0; --i) {
				if (s[i] == 1) stk.push_back(i);
			}
			printf("%d\n%d",1, stk.size());
			while (stk.size()) {
				printf(" %d",stk.back());
				stk.pop_back();
			}
 
			puts("");
 
 
 
		}
	}
	return 0;
}