//greedy
#include <stdio.h>
#include <vector>
using namespace std;
int p[100001];
int pos[100001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i,n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			scanf("%d", p + i);
			pos[p[i]] = i;
		}
		vector<int> ans;
		int tgt = n; int last = n + 1;
		while (ans.size() != n) {
			for (i = pos[tgt]; i < last; ++i)
				ans.push_back(p[i]);
			if(pos[tgt]<last)
				last = pos[tgt];
			--tgt;
		}
		for (auto x : ans) printf("%d ",x);
		puts("");
	}
 
	return 0;
}