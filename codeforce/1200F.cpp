//graph, dp
#include <stdio.h>
#include <stack>
#include <vector>
#define pii pair<int,int>
using namespace std;
int d[1001][2520];
int vis[1001][2520];//0,1( calc not yet),2(calc done)
int n;
int k[1001],m[1001];
int e[1001][10];
int dfs(int x,int c) {
	c += k[x];
	c %= 2520;
	if (c < 0) c += 2520;
	int _c = c % m[x];
	//printf("%d,%d\n", x, _c);
	if (vis[x][c])return d[x][c];
	vis[x][c] = 1;
	vector<pii > hist;
	stack<pii > stk; stk.push({x,c});
	while (1) {
		x = e[x][_c];
		c += k[x];
		c %= 2520;
		if (c < 0) c += 2520;
		_c = c % m[x];
		//printf("%d,%d,%d\n", x, c,stk.size());
		if (vis[x][c] == 1) {
			pii infp = {x,c};
			pii top = stk.top();
			vector<int> mask(1+n);
			do {
				top = stk.top(); stk.pop();
				mask[top.first] = 1;
				hist.push_back(top);
			} while (top != infp);
			int cnt = 0;
			for (auto b : mask)cnt += b;
			for (auto p : hist) {
				x = p.first; c = p.second;
				d[x][c] = cnt;
				vis[x][c] = 2;
			}
			while (stk.size()) {
				top = stk.top(); stk.pop();
				x =top.first; c = top.second;
				d[x][c] = cnt;
				vis[x][c] = 2;
			}
			return cnt;
		}
		else if (vis[x][c] == 2) {
			int cnt = d[x][c];
			while (stk.size()) {
				pii top = stk.top();
				x = top.first; c = top.second;
				stk.pop();
				d[x][c] = cnt;
				vis[x][c] = 2;
			}
			return cnt;
		}
		else {
			vis[x][c] = 1;
			stk.push({x,c});
		}
	}
	return -1;
	
}
int main() {
	int i,j,q;
	
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",k+i);
	for (i = 1; i <= n; ++i) {
		for (scanf("%d", m + i), j = 0; j < m[i]; ++j) scanf("%d",e[i]+j);
	}
	//
	for (scanf("%d", &q); q--;) {
		int x, y; scanf("%d%d",&x,&y);
		printf("%d\n",dfs(x,y));
	}
	return 0;
}