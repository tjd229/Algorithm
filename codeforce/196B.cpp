//category : graph


#include <iostream>
#include <string>
using namespace std;
string map[1500];
bool visit[1500][1500];
int phase_x[1500][1500];
int phase_y[1500][1500];
int N, M;

bool dfs(int x,int y,int x_lap,int y_lap){
	if (x < 0){
		x = M - 1;
		x_lap--;
	}
	if (y < 0){
		y = N - 1;
		y_lap--;
	}
	if (x >= M){
		x = x%M;
		x_lap++;
	}
	if (y >= N){
		y = y%N;
		y_lap++;
	}
	if (map[y][x] == '#') return false;
	//
	if (visit[y][x]) return phase_y[y][x] != y_lap || phase_x[y][x] != x_lap;
	visit[y][x] = true;
	phase_y[y][x] = y_lap;
	phase_x[y][x] = x_lap;
	bool res = false;
	res |= dfs(x + 1, y, x_lap,y_lap);
	res |= dfs(x - 1, y, x_lap,y_lap);
	res |= dfs(x, y + 1, x_lap,y_lap);
	res |= dfs(x, y - 1, x_lap,y_lap);
	return res;
}
int main(){
	int i,j;
	int sx, sy;
	cin >> N >> M;
	for (i = 0; i < N; i++){
		cin >> map[i];
		for (j = 0; j < M; j++){
			if (map[i][j] == 'S'){
				sy = i;
				sx = j;
			}
		}
	}
	cout << (dfs(sx, sy, 0,0) ? "YES" : "NO");
	return 0;
}
