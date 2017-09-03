//category : graph

#include <stdio.h>
int map[50][50];
int w, h;
int dfs(int x,int y){
	if (x < 0 || y < 0 || x >= w || y >= h) return 0;
	if (map[y][x] == 0) return 0;
	
	map[y][x] = 0;
	dfs(x, y + 1);
	dfs(x, y - 1);
	dfs(x + 1, y + 1);
	dfs(x - 1, y + 1);
	dfs(x + 1, y - 1);
	dfs(x - 1, y - 1);
	dfs(x + 1, y);
	dfs(x - 1, y);
	return 1;
}
int main(){
	int i, j;
	int cnt;
	scanf("%d%d",&w,&h);

	while (w!=0&&h!=0){
		cnt = 0;
		for (i = 0; i < h; i++){
			for (j = 0; j < w; j++) scanf("%d", &map[i][j]);
		}
		for (i = 0; i < h; i++){
			for (j = 0; j < w; j++) cnt += dfs(j, i);
		}
		printf("%d\n",cnt);
		scanf("%d%d", &w, &h);
	}

	return 0;
}