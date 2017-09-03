//category : graph



#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int map[100][100];
int N, M, K;
int dfs(int x, int y){
	if (x < 0 || y < 0 || x >= N || y >= M) return 0;
	if (map[y][x] == 1) return 0;
	map[y][x] = 1;
	int size = 1;
	size += dfs(x + 1, y);
	size += dfs(x - 1, y);
	size += dfs(x, y + 1);
	size += dfs(x, y - 1);
	return size;
}
int main(){
	int i, j, k;
	int lx, ly, rx, ry;
	vector<int> v;
	scanf("%d%d%d",&M,&N,&K);
	for (i = 0; i < K; i++){
		scanf("%d%d%d%d",&lx,&ly,&rx,&ry);
		for (j = ly; j < ry; j++){
			for (k = lx; k < rx; k++){
				map[j][k] = 1;
			}
		}
	}
	for (i = 0; i < M; i++){
		for (j = 0; j < N; j++){
			k = dfs(j, i);
			if (k>0) v.push_back(k);
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (i = 0; i < v.size(); i++) printf("%d ",v[i]);
	return 0;
}