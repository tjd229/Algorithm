//greedy
#include <stdio.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int main() {
	int N;
	int S, T;
	int i;
	int mx = 0;
	int cnt = 0;
	vector<pii > evt;
	for (scanf("%d", &N), i = 1; i <= N; ++i) {
		scanf("%d%d",&S,&T);
		evt.push_back({S,1});
		evt.push_back({ T,-1 });
	}
	sort(evt.begin(), evt.end());
	for (auto p : evt) {
		cnt += p.second;
		if (mx < cnt) mx = cnt;
	}
	printf("%d",mx);

	return 0;
}
