//greedy, math
https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4672b
#include <stdio.h>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int C[3], M[3], Y[3], K[3];
int min(int a, int b, int c) {
	return min(a, min(b, c));
}
int main() {
	int T,tc;
	for (scanf("%d", &T), tc = 1; tc <= T; ++tc) {
		printf("Case #%d: ",tc);
		int i;
		ll sum = 0;
		vector<int> ans;
		for (i = 0; i < 3; ++i) scanf("%d%d%d%d",C+i,M+i,Y+i,K+i);
		ans.push_back(min(C[0], C[1], C[2])); sum += ans.back();
		ans.push_back(min(M[0], M[1], M[2])); sum += ans.back();
		ans.push_back(min(Y[0], Y[1], Y[2])); sum += ans.back();
		ans.push_back(min(K[0], K[1], K[2])); sum += ans.back();
		if (sum < 1e6) printf("IMPOSSIBLE\n");
		else {
			i = 3;
			while (sum>1e6) {
				sum -= ans[i];
				ans[i] = 0;
				if (sum < 1e6) {
					int d = (int)1e6 - sum;
					ans[i] = d;
				}
				--i;
			}
			for (auto x : ans)printf("%d ",x);
			printf("\n");
		}
		
	}

	return 0;
}