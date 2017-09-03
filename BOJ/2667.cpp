//category : graph



#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
char map[25][25];
int N;
int fill(int x,int y){
	if (x < 0 || y < 0 || x >= N || y >= N) return 0;
	if (map[x][y] == '0') return 0;
	map[x][y] = '0';
	return fill(x, y - 1) + fill(x, y + 1) + fill(x - 1, y) + fill(x + 1, y) + 1;
}
int main(){
	int i, j;
	vector<int> ans;
	scanf("%d",&N);
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++)
			scanf(" %c",&map[i][j]);
	}
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (map[i][j] == '1') ans.push_back(fill(i, j));
		}			
	}
	sort(ans.begin(), ans.end());
	printf("%d\n",ans.size());
	for (i = 0; i < ans.size(); i++) printf("%d\n",ans[i]);
	return 0;
}