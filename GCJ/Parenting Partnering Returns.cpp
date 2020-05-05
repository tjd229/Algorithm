//implementation
//https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9

#include <stdio.h>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;
char ans[1001];

int main() {
	int tc, T;
	for (scanf("%d", &T), tc = 1; tc <= T; ++tc) {
		int i, N;
		vector<pii > evt;
		vector<char> stk = {'C','J'};
		for (scanf("%d", &N), i = 1; i <= N; ++i) {
			int S, E; scanf("%d%d",&S,&E);
			evt.push_back({S,i});//op
			evt.push_back({E,-i});
		}
		sort(evt.begin(), evt.end());
		bool flag = 1;
		for (auto p : evt) {
			if (p.second>0) {
				if (stk.empty()) {
					flag = 0;
					break;
				}
				ans[p.second] = stk.back();
				stk.pop_back();
			}
			else {
				int ix = -p.second;
				stk.push_back(ans[ix]);
			}
		}
		printf("Case #%d: ",tc);
		if (flag) {
			for (i = 1; i <= N; ++i) printf("%c",ans[i]);
			puts("");
		}
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}