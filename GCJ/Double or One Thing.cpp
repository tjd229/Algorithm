//string, greedy
//https://codingcompetitions.withgoogle.com/codejam/round/0000000000877ba5/0000000000aa8e9c
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define pii pair<int,int>
using namespace std;
char S[101];
int main() {
	int T,tc;
	for (scanf("%d", &T), tc = 1; tc <= T; ++tc) {
		int i, N; scanf(" %s",S);
		vector<pii > p;
		for (i = 0; S[i] != '\0'; ++i) {
			if (p.size() && p.back().first == S[i])
				p.back().second = p.back().second + 1;
			else
				p.push_back({ S[i],1 });
		}
		for (i = 0; i + 1 < p.size(); ++i) {
			if (p[i].first < p[i + 1].first)
				p[i].second = p[i].second * 2;
		}

		printf("Case #%d: ", tc);
		for (auto pp : p) {
			int cnt = pp.second;
			char c = pp.first;
			while (cnt--) printf("%c",c);
		}
		printf("\n");
		
	}

	return 0;
}
	