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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { 1,0,-1,0 };
int n, m;
int w[111][111];
int main() {
	int t; scanf("%d",&t);
	while (t--) {
		int i, j; scanf("%d%d", &n, &m);
		vector<vector<int> > q;
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				scanf("%1d", w[i] + j);
			}
			
		}
		if (w[1][1]) printf("-1\n");
		else {
			for (i = n; i > 0; --i) {
				for (j = m; j > 0; --j) {
					if (w[i][j]) {
						if (j == 1) {
							q.push_back({ i - 1,j,i,j });
						}
						else
							q.push_back({i,j-1,i,j});
					}
				}
			}
			printf("%d\n",q.size());
			for (auto v : q) {
				for (auto x : v) printf("%d ",x);
				printf("\n");
			}
		}
		
		//cout << "\n";
	}
 
 
	return 0;
}