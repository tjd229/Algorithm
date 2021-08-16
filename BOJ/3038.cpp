//graph
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int tree[1<<15];

void dfs(int x,int lev) {
    printf("%d ",tree[x]);
    if(lev>1){
		dfs(x + x, lev - 1);
		dfs(x + x + 1, lev - 1);        
    }
}
int main() {
	int i, N; scanf("%d", &N); tree[1] = 1;
	int mx = (1 << N) - 1;
	vector<int> v = {3,2}, nxt;
	tree[3] = mx--; tree[2] = mx--;
	
	for (int lev = 3; lev < N; ++lev) {
		for (auto x : v) {
			nxt.push_back(x + x + 1);
			tree[x + x + 1] = mx--;
		}
		for (auto x : v) {
			nxt.push_back(x + x );
			tree[x + x ] = mx--;
		}
		v = nxt; nxt.clear();
	}
	//last lev
	reverse(v.begin(), v.end());
	for (auto x : v) tree[x + x + 1] = mx--;
	for (auto x : v) tree[x + x] = mx--;
	
	dfs(1, N);
	return 0;
}
