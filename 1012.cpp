//category : graph

#include <stdio.h>
#include <vector>
using namespace std;
int N, M, K;
int map[50][50];
bool dfs(int x, int y){
	if (x < 0 || y < 0 || x >= M || y >= N) return false;
	if (map[y][x] == 0) return false;
	map[y][x] = 0;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
	return true;
}
int main(){
	int T;
	int X, Y;
	int i;
	int worm = 0;
	for (scanf("%d", &T); T--;){
		vector<pair<int, int> > cabs;
		worm = 0;
		scanf("%d%d%d", &M, &N, &K);
		for (i = 0; i < K; i++){
			scanf("%d%d", &X, &Y);
			
			cabs.push_back(make_pair(X, Y));
			map[Y][X] = 1;
		}
		for (i = 0; i < K; i++) if (dfs(cabs[i].first, cabs[i].second)) worm++;
		printf("%d\n", worm);
	}

	return 0;
}