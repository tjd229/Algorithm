//implementation

#include <stdio.h>
#include <vector>
#define pii pair<int,int>
using namespace std;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int cell[12][12];
vector<pii > core;
pii ans;
int N;
void con(int ix,int on,int tot){
    if (ix == core.size()){
        pii p = { on, -tot };
        if (p > ans) ans = p;
        return;
    }
    int x = core[ix].second;
    int y = core[ix].first;
    int i, j;
    for (i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int len = 0;
        while (nx >= 0 && nx < N && ny >= 0 && ny < N){
            if (cell[ny][nx]) break;
            cell[ny][nx] = 2;
            nx += dx[i];
            ny += dy[i];
            ++len;
        }
        //printf("%d,%d,%d\n",ix,nx,ny);
        if (nx < 0 || ny < 0 || nx == N || ny == N){
            con(ix + 1, on + 1, tot + len);
            nx -= dx[i];
            ny -= dy[i];
            while (!(nx == x && ny == y)){
                cell[ny][nx] = 0;
                nx -= dx[i];
                ny -= dy[i];
            }
        }
        else{
            nx -= dx[i];
            ny -= dy[i];
            while (!(nx == x && ny == y)){
                cell[ny][nx] = 0;
                nx -= dx[i];
                ny -= dy[i];
            }
            con(ix + 1, on, tot);
        }
    }
}
int main(){
    int i, j;
    int T;
    int X;
    for (scanf("%d", &T), X = 1; X <= T; X++){
        core.clear();
        int base = 0;
        for (scanf("%d", &N), i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                scanf("%d", &cell[i][j]);
                if (cell[i][j]){
                    if (i == 0 || j == 0 || i == N - 1 || j == N - 1) base++;
                    else core.push_back({ i, j });
                }
            }
        }
        ans = { 0, 0 };
        con(0, base, 0);
        printf("#%d %d\n",X,-ans.second);
        //printf("%d\n",ans.first);
    }
 
    return 0;
}
