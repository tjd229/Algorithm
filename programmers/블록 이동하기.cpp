//graph
//https://programmers.co.kr/learn/courses/30/lessons/60063
#include <string>
#include <vector>
#include <queue>

using namespace std;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

int vis[100][100][2];

struct Tuple { int x, y, dir; };
int solution(vector<vector<int>> board) {
	int N = board.size();
	
	queue<Tuple> q;
	q.push({0,0,0});
	vis[0][0][0] = 1;
	while (q.size()) {
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		int t = vis[y][x][dir];
		q.pop();
		//printf("%d,%d,%d,%d\n",x,y,dir,t);
		if (x == N - 1 && y == N - 1)
			return t-1;

		if (x + dx[dir] == N - 1 && y + dy[dir] == N - 1)
			return t-1;

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (ny < 0 || nx < 0 || nx >= N || ny >= N) continue;
			if (ny + dy[dir] < 0 || ny + dy[dir] >= N
				|| nx + dx[dir] < 0 || nx + dx[dir] >= N) continue;
			if (board[ny][nx] || board[ny + dy[dir]][nx + dx[dir]]) continue;
			if (vis[ny][nx][dir] == 0) {
				q.push({ nx,ny,dir });
				vis[ny][nx][dir] = t + 1;
			}
			
			
		}
		if (x + 1 < N && y + 1 < N && board[y + 1][x] + board[y][x + 1] + board[y + 1][x + 1] == 0) {
			if (vis[y][x][1 - dir] == 0) {
				q.push({ x,y,1 - dir });
				vis[y][x][1 - dir] = t + 1;
			}			
			if (vis[y + dy[dir]][x + dx[dir]][1 - dir] == 0) {
				q.push({ x + dx[dir],y + dy[dir],1 - dir });
				vis[y + dy[dir]][x + dx[dir]][1 - dir] = t + 1;
			}
			
				
		}
		if (dir) {// |
			if (x - 1 >= 0 &&  board[y + 1][x] + board[y][x - 1] + board[y + 1][x - 1] == 0) {
				if (vis[y][x - 1][1 - dir] == 0) {
					q.push({ x - 1,y,1 - dir });
					vis[y][x - 1][1 - dir] = t + 1;
				}
				if (vis[y + 1][x - 1][1 - dir] == 0) {
					q.push({x-1,y+1,1-dir});
					vis[y + 1][x - 1][1 - dir] = t + 1;
				}
			}
		}
		else {//-
			if (y - 1 >= 0 && board[y - 1][x] + board[y - 1][x + 1] == 0) {
				if (vis[y - 1][x][1 - dir] == 0) {
					q.push({x,y-1,1-dir});
					vis[y - 1][x][1 - dir] = t + 1;
				}
				if (vis[y - 1][x + 1][1 - dir] == 0) {
					q.push({x+1,y-1,1-dir});
					vis[y - 1][x + 1][1 - dir] = t + 1;
				}
			}
		}
	}
	return -1;
}