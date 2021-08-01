//graph, SCC
#include <stdio.h>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int k[501];
int ask(int A, int B) {
	printf("? %d %d\n", A, B); fflush(stdout);
	char s[5]; scanf(" %s",s);
	return s[0] == 'Y';
}
int main() {
	int i, n;
	vector<tuple<int, int, int> > v;
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",k+i);
	for (i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (k[i] <= k[j])
				v.push_back({ k[j] - k[i], j,i });
			else
				v.push_back({k[i]-k[j],i,j});
		}
	}
	sort(v.begin(), v.end());
	while (v.size()) {
		int A, B; tie(ignore, A, B) = v.back();
		v.pop_back();
		if (ask(A, B)) {
			printf("! %d %d\n", A, B); fflush(stdout);
			return 0;
		}
	}
	printf("! %d %d\n",0,0); fflush(stdout);
	return 0;
}