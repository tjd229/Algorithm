//category : graph

#include <stdio.h>
#include <queue>
using namespace std;
char map[100][100];
int N, M;
bool isPath(int x, int y){
	if (x < 0 || y < 0 || x >= M || y >= N) return false;
	if (map[y][x] == '0') return false;
	map[y][x] = '0';
	return true;
}
int main(){	
	
	int x, y;
	int level = 0;
	queue<pair<int, int> > q;
	scanf("%d%d",&N,&M);
	for (y = 0; y < N; y++) for(x=0;x<M;x++) scanf(" %c",&map[y][x]);
	q.push(make_pair(0, 1));
	map[0][0] = '0';
	while (true){
		x = q.front().first % M;
		y = q.front().first / M;
		level = q.front().second;
		if (x == M - 1 && y == N - 1) break;
		if (isPath(x, y + 1)) q.push(make_pair(q.front().first + M, level + 1));
		if (isPath(x, y - 1)) q.push(make_pair(q.front().first - M, level + 1));
		if (isPath(x+1, y )) q.push(make_pair(q.front().first + 1, level + 1));
		if (isPath(x-1, y )) q.push(make_pair(q.front().first -1, level + 1));
		q.pop();

	}
	printf("%d",level);

	return 0;
}
