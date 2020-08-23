//greedy
#include <stdio.h>
#include <vector>
using namespace std;
char s[200001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf(" %c",s+i);
		vector<int> seg = { 0 };
		int piv = s[1];
		for (i = 1; i <= n; ++i) {
			if (piv == s[i]) ++seg.back();
			else {
				seg.push_back(1);
				piv = s[i];
			}
		}
		if (seg.size() == 1) {
			int ans = seg[0] / 3 + ((seg[0] % 3) > 0);
			printf("%d\n",ans);
		}
		else {
			if (s[1] == s[n]) {
				seg[0] += seg.back();
				seg.pop_back();
			}
			int ans = 0;
			for (auto x : seg) ans += x / 3;
			printf("%d\n",ans);
		}
		
	}
 
	return 0;
}