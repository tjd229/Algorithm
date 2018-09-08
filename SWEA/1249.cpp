//graph, dijkstra

#include <stdio.h>
#include <queue>
#define pii pair<int,int>
using namespace std;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int map[100][100];
int d[100][100];
int visit[100 * 100 + 1];
int N;
int to1D(int x,int y){
    return x + y*N;
}
int main(){
    int i, j;
    int C, T;
    //freopen("input.txt","r",stdin);
    for (scanf("%d", &T), C = 1; C <= T; C++){
        for (scanf("%d", &N), i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                scanf("%1d",&map[i][j]);
                d[i][j] = 1e9;
            }
        }
        priority_queue<pii > q;
        q.push({0,to1D(0,0)});
        d[0][0] = 0;
        while (q.size()){
            int ix = q.top().second;
            q.pop();
            if (visit[ix] == C) continue;
            visit[ix] = C;
            int x = ix%N;
            int y = ix / N;
            if (x + y == N + N-2) break;
            for (i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx>=0 && nx < N && ny >= 0 && ny < N){
                    if (d[y][x] + map[ny][nx] < d[ny][nx]){
                        d[ny][nx] = d[y][x] + map[ny][nx];
                        q.push({ -d[ny][nx], to1D(nx, ny) });
                    }
                }
            }
        }
        printf("#%d %d\n",C,d[N-1][N-1]);
 
    }
 
    return 0;
}
