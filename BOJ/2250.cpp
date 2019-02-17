//graph
#include <stdio.h>
#include <vector>
using namespace std;
int l[10001], r[10001];
int dl[10001], dr[10001];
int d[10001];
vector<int> hist;
void dfs(int x) {
	if (l[x]>0) {
		d[l[x]] = d[x] + 1;
		dfs(l[x]);
	}
	hist.push_back(x);
	if (r[x]>0) {
		d[r[x]] = d[x] + 1;
		dfs(r[x]);
	}
}
int main() {
	int i, N;
	int lev, w;
	int root = 0;
	for (scanf("%d", &N), i = 1; i <= N; ++i) {
		int x; scanf("%d",&x);
		scanf("%d%d",l + x, r + x);
		dl[i-1] = dr[i-1] = -1;
		root += i;
		if (l[x] > 0) root -= l[x];
		if (r[x] > 0) root -= r[x];
	}
	dfs(root);
	w = 0;
	for (i = 0; i < N; ++i) {
		int depth = d[hist[i]];
		if (dl[depth] < 0) dl[depth] = i;
		dr[depth] = i;
		int width = dr[depth] - dl[depth]+1;
		if (w < width) {
			w = width;
			lev = depth;
		}
		else if (w == width && lev > depth) lev = depth;
	}
	printf("%d %d",lev+1,w);
	return 0;
}