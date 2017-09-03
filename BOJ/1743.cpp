//category : graph

#include <stdio.h>
#include <vector>
using namespace std;
int N, M, K;
int map[101][101];
int dfs(int x, int y){
	if (x < 1 || y < 1 || x > M || y > N) return 0;
	if (map[y][x] == 0) return 0;
	map[y][x] = 0;
	int size = 1;
	size+=dfs(x + 1, y);
	size+=dfs(x - 1, y);
	size+=dfs(x, y + 1);
	size+=dfs(x, y - 1);
	return size;
}
int main(){
	scanf("%d%d%d",&N,&M,&K);
	vector<pair<int, int> >v;
	int x, y;
	int i;
	int ans = 0;
	for (i = 0; i < K; i++){
		scanf("%d%d",&y,&x);
		map[y][x] = 1;
		v.push_back(make_pair(x,y));
	}
	for (i = 0; i < K; i++){
		x = dfs(v[i].first,v[i].second);
		if (ans < x) ans = x;
	}
	printf("%d",ans);
	return 0;
}