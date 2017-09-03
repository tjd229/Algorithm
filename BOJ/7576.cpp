//category : graph

#include <stdio.h>
#include <queue>
using namespace std;
int map[1000][1000];
int M, N;
bool tomato(int x,int y){
	if (x < 0 || y < 0 || x >= M || y >= N) return false;
	if (map[y][x] !=0) return false;
	map[y][x] = 1;
	return true;
}
int main(){
	int num;
	int cnt = 0;
	int level=-1;
	int i, j;
	queue<pair<int, int> > q;
	scanf("%d%d",&M,&N);
	num = M*N;
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1) num--;
			if (map[i][j] == 1) q.push(make_pair(j+i*M,0)),cnt++;
		}
	}
	if (cnt == num) return printf("0");
	while (!q.empty()){
		i = q.front().first / M;
		j = q.front().first % M;
		level = q.front().second;
		if (tomato(j, i + 1)) q.push(make_pair(q.front().first + M, level + 1)),cnt++;
		if (tomato(j, i - 1)) q.push(make_pair(q.front().first - M, level + 1)),cnt++;
		if (tomato(j+1, i)) q.push(make_pair(q.front().first + 1, level + 1)),cnt++;
		if (tomato(j-1, i)) q.push(make_pair(q.front().first - 1, level + 1)),cnt++;
		if (cnt == num) break;
		q.pop();
	}
	printf("%d",cnt==num? level+1:-1);

	return 0;
}